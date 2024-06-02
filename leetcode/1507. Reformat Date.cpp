class Solution 
{
public:
    string get_string_month(const string& month)
    {
        if (month == "Jan") return "01";
        else if (month == "Feb") return "02";
        else if (month == "Mar") return "03";
        else if (month == "Apr") return "04";
        else if (month == "May") return "05";
        else if (month == "Jun") return "06";
        else if (month == "Jul") return "07";
        else if (month == "Aug") return "08";
        else if (month == "Sep") return "09";
        else if (month == "Oct") return "10";
        else if (month == "Nov") return "11";
        else  return "12";
    }

    string get_string_date(const string& day)
    {
        if (day.size() == 3) 
        {
            return "0" + day.substr(0, 1);
        }

        return day.substr(0, 2);
    }

    string reformatDate(const string& date) 
    {
        vector<string> words;
        stringstream sstream(date);
        string word;

        while(getline(sstream, word, ' '))
        {
            words.push_back(word);
        }

        const string year = words[2];
        const string month = get_string_month(words[1]);
        const string day = get_string_date(words[0]);

        return year + "-" + month + "-" + day;
    }
};
// https://leetcode.com/problems/reformat-date/description/
