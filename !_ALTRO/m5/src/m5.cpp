#include <iostream>
#include <set>
using namespace std;



int main()
{


	for(int i = 1; i <= 2146; i++)
	{
		int a = i*i;
		int b = a*i;

		string as = to_string(a);
		string bs = to_string(b);

		set <int> s;
		bool stop = false;

		for(int j = 0; j < as.length(); j++)
		{
			int tmp = stoi(as.substr(j, 1));
			if(s.find(tmp) == s.end())
				s.insert(tmp);
			else
			{
				stop = true;
				break;
			}
		}
		if(stop)
			continue;

		for(int j = 0; j < bs.length(); j++)
		{
			int tmp = stoi(bs.substr(j, 1));
			if(s.find(tmp) == s.end())
				s.insert(tmp);
			else
			{
				stop = true;
				break;
			}
		}


		if(stop)
			continue;
		else if(s.size() == 10)
		{
			cout << i;
			break;
		}

	}


}
