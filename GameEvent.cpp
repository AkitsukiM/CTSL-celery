#include "GameEvent.h"
#include "PersonLog.h"

extern map<string, PersonLog> personlogs;

void GameEvent::update_winner()
{
	// »Ùwinner∑«ø’
	if (!winner.empty() && point_winner != 0)
	{
		for (vector<PointEvent>::iterator iter = winner.begin(); iter != winner.end(); ++iter)
		{
			(*iter).update_point(point_sum, point_winner);
			personlogs[(*iter).read_qqnumber()].write_pointevents(*iter);
		}
	}
}

