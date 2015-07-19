//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <cctype>
//
//using namespace std;
//
//bool not_url_char(char c)
//{
//	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
//
//	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
//}
//
//
//string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
//{
//	return find_if(b, e, not_url_char);
//}
//
//
//string::const_iterator url_begin(string::const_iterator b, string::const_iterator e)
//{
//	static const string sep = "://";
//	typedef string::const_iterator iter;
//	iter i = b;
//
//	while ((i = search(i, e, sep.begin(), sep.end())) != e)
//	{
//		if (i != b && i + sep.size() != e)
//		{
//			iter beg = i;
//
//			while (beg != b && isalpha(*(beg-1)))
//				beg--;
//
//			if (beg != i && !not_url_char(*(i + sep.size())))
//				return beg;
//		}
//		i += sep.size();
//	}
//	return e;
//}
//
//
//vector<string> find_urls(const string& s)
//{
//	vector<string> ret;
//	typedef string::const_iterator iter;
//	iter b = s.begin(), e = s.end();
//
//	while (b != e)
//	{
//		b = url_begin(b, e);
//
//		if (b != e)
//		{
//			iter after = url_end(b, e);
//			ret.push_back(string(b, after));
//			b = after;
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	vector<string> lines, output_url;
//	string s;
//
//	while (getline(cin, s))
//	{
//		lines.push_back(s);
//	}
//
//	for (vector<string>::const_iterator iter = lines.begin();
//		iter != lines.end(); ++iter)
//	{
//		output_url = find_urls(*iter);
//
//		for (vector<string>::const_iterator it = output_url.begin();
//			it != output_url.end(); ++it)
//			cout << *it << endl;
//	}
//
//	system("pause");
//	return 0;
//}