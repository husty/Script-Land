--[[ WoTD License - 
This software is provided as free and open source by the
team of The WoTD Team. This script was written and is
protected by the GPL v2. Please give credit where credit
is due, if modifying, redistributing and/or using this 
software. Thank you.
Thank: WoTD Team; for the Script
~~End of License... Please Stand By...
-- WoTD Team, Janurary 19, 2010. ]]

function SunreaverScout_OnCombat(Unit, Event)
	Unit:RegisterEvent("SunreaverScout_MultiShot", 8000, 0)
	Unit:RegisterEvent("SunreaverScout_Shoot", 6000, 0)
end

function SunreaverScout_MultiShot(Unit, Event) 
	Unit:FullCastSpellOnTarget(14443, Unit:GetMainTank()) 
end

function SunreaverScout_Shoot(Unit, Event) 
	Unit:FullCastSpellOnTarget(6660, Unit:GetMainTank()) 
end

function SunreaverScout_OnLeaveCombat(Unit, Event) 
	Unit:RemoveEvents() 
end

function SunreaverScout_OnDied(Unit, Event) 
	Unit:RemoveEvents()
end

RegisterUnitEvent(30233, 1, "SunreaverScout_OnCombat")
RegisterUnitEvent(30233, 2, "SunreaverScout_OnLeaveCombat")
RegisterUnitEvent(30233, 4, "SunreaverScout_OnDied")