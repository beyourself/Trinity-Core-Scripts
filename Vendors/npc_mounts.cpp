/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_mounts'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_mount : public CreatureScript
{
	public:
		multi_mount() : CreatureScript("multi_mount")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Spell_Arcane_Arcane04:24|t|r Special Offers", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Ability_Mount_BigBlizzardBear:24|t|r Ground Mounts", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Ability_Mount_FlyingCarpet:24|t|r Flying Mounts", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 3);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			WorldSession * m_session = Player->GetSession();
			
			switch(uiAction)
			{
				case 0:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500033);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_mount()
{
	new multi_mount();
}