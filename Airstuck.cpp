class CAirStuck
{
private: void Set_MoveValue(float forwardmove, float sidemove)
	{
		usercmd_s* pCmd = cmd::get();

		pCmd->forwardmove = forwardmove;
		pCmd->sidemove = sidemove;
	}

public: void CL_CreateMove()
	{
		float AirStuck_POWER = 0;

		if (cvar.movement.airstuck_enabled) return;

		if ((g_Local.m_bIsDead || g_Local.m_iTeam == SPECTATOR) || (cvar.movement.airstuck_key && !state.airstuck_active))
			return;

		if (cvar.movement.airstuck_power == 1) AirStuck_POWER = 0.955; 
		if (cvar.movement.airstuck_power == 2) AirStuck_POWER = 0.975;
		if (cvar.movement.airstuck_power == 3) AirStuck_POWER = 0.985;
		if (cvar.movement.airstuck_power == 4) AirStuck_POWER = 0.999;
		if (cvar.movement.airstuck_power == 5) AirStuck_POWER = 0.9999;

		if (cvar.movement.airstuck_enabled && cvar.movement.airstuck_key)
		{
			g_Utils.AdjustSpeed(1.0 - AirStuck_POWER);

			if (cvar.movement.airstuck_autoreduce_speed)
			{
				if (g_Local.m_flVelocity > 200)       Set_MoveValue(-1000, -1000);
				else if (g_Local.m_flVelocity <= 200) Set_MoveValue(-100, -100);
				else if (g_Local.m_flVelocity <= 120) Set_MoveValue(-10, -10);
				else if (g_Local.m_flVelocity <= 50)  Set_MoveValue(-1, -1);
				else if (g_Local.m_flVelocity <= 0)   Set_MoveValue(0, 0);
			}
		}
	}
};
