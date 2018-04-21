#include <string>
#include <vector>
#include "day.h"

using namespace std;

class day {
private:

	string day;
	vector <event> events;
	int wake;
	int sleep;

public:
	//creates a day
	day(string d) {
		day = d;
	}

	//sets the name of the day
	void setDay(string d) {
		day = d;
	}

	//returns the name of the day
	string getDay() {
		return day;
	}

	//adds an event if theres not already something at that time
	bool addEvent(assignment a) {

		int time = a.getTime;
		//goes through the events and returns false if event cannot be added
		for (int x = 0; x < events.size(); x++) {
			int start = events[x].getTime();
			int end = events[x].getLength() + start;
			int eventEnd = a.getTime() + a.getLength();
			if (a.getTime() >= start && a.getTime <= end) {
				return false;
			}
			if (eventEnd >= start && eventEnd <= end) {
				return false;
			}
			events.push_back(a);
		}
		return true;
	}

	//removes event by name
	bool removeEvent(assignment a) {
		bool removed = false;
		for (int x = 0; x < events.size(); x++) {
			if (events[x] == a) {
				events.erase(events.begin() + x);
				removed = true;
			}
		}
		return removed;
	}

	//returns the vector of events
	vector <events> getEvents() {
		return events;
	}	
	
	void setWake(int n)
	{
		wake = n;
	}

	int getWake()
	{
		return wake;
	}

	void setSleep(int n)
	{
		sleep = n;
	}

	int getSleep()
	{
		return sleep;
	}

};

			
