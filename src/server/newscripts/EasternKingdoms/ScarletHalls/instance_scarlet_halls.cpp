/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scarlet_halls.h"


#define MAX_ENCOUNTER 3

class instance_scarlet_halls : public InstanceMapScript
{
public:
    instance_scarlet_halls() : InstanceMapScript("instance_scarlet_halls", 1001) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_scarlet_halls_InstanceMapScript(map);
    }

    struct instance_scarlet_halls_InstanceMapScript : public InstanceScript
    {
        instance_scarlet_halls_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 encounter[MAX_ENCOUNTER];
        uint64 BraunGUID;
        uint64 HarlanGUID;
        uint64 KoeglerGUID;

        void Initialize()
        {
            memset(&encounter, 0, sizeof(encounter));
            BraunGUID = 0;
            HarlanGUID = 0;
            KoeglerGUID = 0;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_HOUNDMASTER_BRAUN:    
                    BraunGUID = creature->GetGUID(); 
                    break;
                case NPC_ARMSMASTER_HARLAN:        
                    HarlanGUID = creature->GetGUID(); 
                    break;
                case NPC_FLAMEWEAVER_KOEGLER:     
                    KoeglerGUID = creature->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                default:
                    break;
            }
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_HOUNDMASTER_BRAUN:   
                    return BraunGUID;
                case NPC_ARMSMASTER_HARLAN:              
                    return HarlanGUID;
                case NPC_FLAMEWEAVER_KOEGLER:                  
                    return KoeglerGUID;
            }
            return 0;
        }

        uint32 GetData(uint32 type)
        {
            return 0;
        }
    };
};

void AddSC_instance_scarlet_halls()
{
    new instance_scarlet_halls();
}