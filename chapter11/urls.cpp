#include <algorithm>
#include <cctype>
#include <string>
#include "Vec.h"
#include "urls.h"

using namespace std;

bool not_url_char(char);  

string::const_iterator url_end(string::const_iterator, string::const_iterator);  

string::const_iterator url_beg(string::const_iterator, string::const_iterator); 

Vec<string> find_urls(const string& s)
{
	Vec<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);

		if (b != e)
		{
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}

	return ret;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// ������ĸ�����ֻ�������url_ch�г���
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;
	iter i = b;

	while ( (i = search(i, e, sep.begin(), sep.end())) != e)
	{
		if (i != b && i + sep.size() != e)
		{
			iter beg = i;
			while (beg != b && isalpha(*(beg-1)) )
				--beg;

			if (beg != i && !not_url_char(*(i+sep.size())))
				return beg;
		}

		i += sep.size();
	}

	return e;
}