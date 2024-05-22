class AirStuck
{
void Set_MoveValue(float ForwardMove, float SideMove)
{
	usercmd_s* pCmd = cmd::get();

	pCmd->forwardmove = ForwardMove;
	pCmd->sidemove = SideMove;
}

public: void CL_CreateMove()
	{
		float Power = NULL;

		if (cvar.movement.airstuck_enabled) return;

		if ((g_Local.m_bIsDead || g_Local.m_iTeam == SPECTATOR) || (cvar.movement.airstuck_key && !state.airstuck_active))
			return;

		switch (cvar.movement.airstuck_power)
		{
			case 1: Power = 0.955; break;
			case 2: Power = 0.975; break;
			case 3: Power = 0.985; break;
			case 4: Power = 0.999; break;
			case 5: Power = 0.9999; break;
		}

		if (cvar.movement.airstuck_enabled && cvar.movement.airstuck_key)
		{
			g_Utils.AdjustSpeed(1.0 - Power);

			if (cvar.movement.airstuck_autoreduce_speed)
			{
				if (g_Local.m_flVelocity > 200)        
					Set_MoveValue(-1000, -1000);
					
				else if (g_Local.m_flVelocity <= 200)  
					Set_MoveValue(-100, -100);
					
				else if (g_Local.m_flVelocity <= 120)  
					Set_MoveValue(-10, -10);
					
				else if (g_Local.m_flVelocity <= 50)  
					Set_MoveValue(-1, -1);
					
				else if (g_Local.m_flVelocity <= NULL)
					Set_MoveValue(NULL, NULL);
			}
		}
	}
};
