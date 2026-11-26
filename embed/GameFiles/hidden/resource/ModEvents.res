//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//=============================================================================

// No spaces in event names, max length 32
// All strings are case sensitive
//
// valid data key types are:
//   string : a zero terminated string
//   bool   : unsigned int, 1 bit
//   byte   : unsigned int, 8 bit
//   short  : signed int, 16 bit
//   long   : signed int, 32 bit
//   float  : float, 32 bit
//   local  : any data, but not networked to clients
//
// following key names are reserved:
//   local      : if set to 1, event is not networked to clients
//   unreliable : networked, but unreliable
//   suppress   : never fire this event
//   time	: firing server time
//   eventid	: holds the event ID

"cstrikeevents"
{
	"player_death"				// a game event, name may be 32 charaters long
	{
		// this extents the original player_death by a new 
		// field "headshot", all other fields remains the same
		"userid"	"short"		// user ID of player that died
		"attacker"	"short"		// user ID of attacker
		"weapon"	"string" 	// weapon name killed used 
		"headshot"	"bool"		// signals a headshot
	}
	
	"player_hurt"
	{
		"userid"	"short"
		"attacker"	"short"
		"damage"	"float"
		"hidden"	"bool"
	}
	
	"alarm_trigger"
	{
		"posx"	"float"
		"posy"	"float"
		"posz"	"float"
	}
	
	"aura_start"
	{
		"userid"	"short"
		"duration"	"float"
	}
	
	"aura_end"
	{
		"userid"	"short"
	}
	
	"material_check"
	{
		"vmt_CRC"	"long"
		"bump_CRC"	"long"

	}
	
	"extraction_start"
	{
		"time" "float"
	}
	
	"extraction_stop"
	{
		
	}
	
	"evacuation_complete"
	{
	
	}
	
	"extraction_timer_start"
	{
		"tot_time"	"short"
		"cur_time"	"short"
		"userid"	"short"
	}
	
	"extraction_timer_finish"
	{
	
	}
	
	"player_location"
	{
		"userid"	"short"
		"location"	"string"
	}
	
	"iris_wins"
	{
	}
	
	"iris_radio"
	{
		"userid"	"short"
		"message"	"short"
	}
	
	"game_round_restart"
	{
	
	}
	
	"game_round_end"
	{
	
	}

	"game_round_start"
	{
	
	}	
}
