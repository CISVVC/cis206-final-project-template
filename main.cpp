#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>

const int ISO_CODE = 0;
const int LOCATION = 1;
const int DATE = 2;

const std::vector<std::string> FIELDS = {
"iso_code","location","date",
"total_cases","new_cases","total_deaths","new_deaths","total_cases_per_million","new_cases_per_million","total_deaths_per_million","new_deaths_per_million","total_tests","new_tests","total_tests_per_thousand","new_tests_per_thousand","new_tests_smoothed","new_tests_smoothed_per_thousand","tests_units","stringency_index","population","population_density","median_age","aged_65_older","aged_70_older","gdp_per_capita","extreme_poverty","cvd_death_rate","diabetes_prevalence","female_smokers","male_smokers","handwashing_facilities","hospital_beds_per_100k"
};


struct DictionaryStruct {
   int index;
   std::string key;
   std::string description;
   std::string source;
};

typedef std::map<std::string,DictionaryStruct> Dictionary;
//               iso_code             date        data
typedef std::map<std::string,std::vector<std::string> > DateRecordMap;
typedef std::map<std::string,DateRecordMap > RecordMap;

void print_dictionary(Dictionary dict)
{
   for(auto d : dict)
   {
      std::cout << d.first << "|" << d.second.index << "|" 
                << d.second.description << "|" << d.second.source << std::endl;
   }
}

void print_records(std::vector<std::string> v)
{
   for(std::string s : v)
      std::cout << s << " ";
   std::cout << std::endl;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token; 
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {  
      tokens.push_back(token);
   }
   return tokens;
}

void read_dictionary(std::istream &ifs,Dictionary &d)
{
   
   int index = 0;
   while(!ifs.eof())
   {
      std::string line;
      std::getline(ifs,line);
      if(!ifs.eof())
      {
         std::vector<std::string> r = split(line,'|');
         DictionaryStruct h;
         h.index = index;
         h.key = r[0];
         h.description = r[1];
         h.source = r[2];
         d[h.key] = h;
         index++;
      }
   }
}

void read_records(std::istream &ifs,RecordMap &m)
{
   std::string header;
   std::getline(ifs,header);  // reads the header
   bool done = false;
   while(!done)
   {
      std::string line;
      std::getline(ifs,line);
      std::vector<std::string> v = split(line,',');
      if(!ifs.eof())
      {
           std::string prev = v[ISO_CODE];
           DateRecordMap *dm = new DateRecordMap;
           while(!ifs.eof())
           {
               if(v[ISO_CODE] == prev)
               {
                  (*dm)[v[DATE]] = v;
               }
               else 
               {
                  if(prev.size() != 0)
                  {
                     m[prev] = *dm;
                     prev = v[ISO_CODE];
                     delete dm;
                     dm = new DateRecordMap;
                  }
               }
               std::getline(ifs,line);
               v = split(line,',');
           }

//               iso_code             date        data
//typedef std::map<std::string,std::map<std::string,std::vector<std::string> > > RecordMap;
//
           
      }
      else {
         done = true;
      }

   }
}

std::string indent(int level)
{
   std::string l="";
   for(int i=0;i<level;i++)
      l += " ";

   return l;
}
const char DBL_Q =  '"';
const char COMMA =  ',';
void print_records(const RecordMap &map) 
{
   for(auto r : map)
   {
      std::cout << DBL_Q << r.first << DBL_Q << " :  { "<< std::endl;
      int level = 4;
      for(auto d : r.second) 
      {
         std::cout << indent(level) << DBL_Q << d.first << DBL_Q << " :  {" << std::endl;  // this is the date
         for(int i=0;i<d.second.size();i++)
            std::cout << indent(level*2) << DBL_Q << FIELDS[i] << DBL_Q << " : " << DBL_Q << d.second[i] << DBL_Q << COMMA<< std::endl;
         std::cout << indent(level) << "}" << COMMA << std::endl;
      }
      std::cout << "}" << COMMA << std::endl;
   }
}


int main()
{
   Dictionary dictionary;
   RecordMap records;
   std::ifstream ifs("codebook.md");
   read_dictionary(ifs,dictionary);
   //print_dictionary(dictionary);
   std::ifstream ovid("owid-covid-data.csv");
   read_records(ovid,records);
   print_records(records);
   return 0;
}
