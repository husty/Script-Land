--[[ WoTD License - 
This software is provided as free and open source by the
team of The WoTD Team. This script was written and is
protected by the GPL v2. Please give credit where credit
is due, if modifying, redistributing and/or using this 
software. Thank you.
Thank: WoTD Team; for the Script
~~End of License... Please Stand By...
-- WoTD Team, Janurary 19, 2010. ]]

local GoId = 180796

function WinterWondervoltOnSpawn(event, player)
	if(player:InFront() == true) then
		if((player:GetDistance() <= 2) == true) then
			player:CastSpell(26272)
		end
	end
end

RegisterGameObjectEvent(GoId, 2, "WinterWondervoltOnSpawn")