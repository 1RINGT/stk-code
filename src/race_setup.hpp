//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_RACESETUP_H
#define HEADER_RACESETUP_H

#include <string>
#include <vector>

enum RaceDifficulty { RD_EASY, RD_MEDIUM, RD_HARD };

/** A class that manages all configurations that are needed for a
    single race */
class RaceSetup
{
protected:
    std::string m_herring_style;
public:
    enum RaceMode { RM_TIME_TRIAL, RM_QUICK_RACE, RM_GRAND_PRIX };

    RaceSetup()
    {
        m_mode          = RM_QUICK_RACE;
        m_difficulty    = RD_EASY;
        m_num_laps      = 3;
        m_track         = "race";
        m_herring_style = "";
    }

    RaceMode  m_mode;
    RaceDifficulty  m_difficulty;
    int   m_num_laps;

    /** Ident of the track to use */
    std::string m_track;

    // FIXME: This could probally be a bit more robust/easier to understand

    typedef std::vector<int> Players;
    /** Positions of the karts which should be controlled by
        players */
    Players m_players;

    typedef std::vector<std::string> Karts;
    /** kart idents that should be used in the race, the karts
        will be used in the order in which they are given */
    Karts m_karts;

    unsigned int getNumKarts()  const { return (unsigned int) m_karts.size(); }
    int getNumPlayers() const                 { return (int)m_players.size(); }
    const std::string& getHerringStyle()          const {return m_herring_style;}
    const void         setHerringStyle(const std::string& s) {m_herring_style=s;}
};

#endif

/* EOF */
