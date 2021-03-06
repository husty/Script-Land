/*
 * ArcPro MMORPG Server
 * Copyright (c) 2011-2013 ArcPro Speculation <http://arcpro.sexyi.am/>
 * Copyright (c) 2008-2013 ArcEmu Team <http://www.arcemu.org/>
 * Copyright (c) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Setup.h"

// XpEleminatorGossip
//  GossipScript subclass for turning on/off Player experience gain
class XpEliminatorGossip : public Arcpro::Gossip::Script
{
	public:
		XpEliminatorGossip()
		{
			GOSSIP_DISABLE_XP_GAIN = "I no longer wish to gain experience.";
			GOSSIP_ENABLE_XP_GAIN = "I wish to start gaining experience again";

			GOSSIP_BOXMSG_DISABLE_XP_GAIN = "Are you certain you wish to stop gaining experience?";
			GOSSIP_BOXMSG_ENABLE_XP_GAIN = "Are you certain you wish to start gaining experience again?";
		}

		void OnHello(Object* pObject, Player* plr)
		{
			Arcpro::Gossip::Menu menu(pObject->GetGUID(), 14736);
			if(plr->CanGainXp())
				menu.AddItem(Arcpro::Gossip::ICON_CHAT, GOSSIP_DISABLE_XP_GAIN, 1, 100000, GOSSIP_BOXMSG_DISABLE_XP_GAIN);
			else
				menu.AddItem(Arcpro::Gossip::ICON_CHAT, GOSSIP_ENABLE_XP_GAIN, 1, 100000, GOSSIP_BOXMSG_ENABLE_XP_GAIN);

			menu.Send(plr);
		}

		void OnSelectOption(Object* pObject, Player* plr, uint32 Id, const char* Code)
		{
			// turning xp gains on/off costs 10g each time
			if(plr->HasGold(100000))
			{
				plr->ModGold(-100000);
				plr->ToggleXpGain();
			}
			Arcpro::Gossip::Menu::Complete(plr);
		}

		void Destroy() { delete this; }

	private:
		const char* GOSSIP_DISABLE_XP_GAIN;
		const char* GOSSIP_ENABLE_XP_GAIN;

		const char* GOSSIP_BOXMSG_DISABLE_XP_GAIN;
		const char* GOSSIP_BOXMSG_ENABLE_XP_GAIN;

};

void SetupXpEliminatorGossip(ScriptMgr* mgr)
{

	Arcpro::Gossip::Script* xegs = new XpEliminatorGossip();

	mgr->register_creature_gossip(35364, xegs);    // Slahtzt the Horde NPC
	mgr->register_creature_gossip(35365, xegs);    // Besten the Alliance NPC
}
