# Final Project CIS206 Step 1

> Write a Java program which will convert a CSV file containing covid 19 data into javascript object notation (JSON)
> format.
> The covid19 file can be found at this URL 
[https://github.com/owid/covid-19-data/blob/master/public/data/owid-covid-data.csv](https://github.com/owid/covid-19-data/blob/master/public/data/owid-covid-data.csv)
> For this project, you will want to use a combination of ArrayList (or a regular array) and one of the Map Collections
> Hashmap or Tree Map.  The conversion will involve reading the data file line by line reading it into the appropriate
> structure.  Do this in a method called ***read_records***. When the structure is filled, then send the structure to a method called ***print_records*** which will print it out in the following format:
<pre><code>
"ABW" :  { 
    "2020-03-13" :  {
        "iso_code" : "ABW",
        "location" : "Aruba",
        "date" : "2020-03-13",
        "total_cases" : "2",
        "new_cases" : "2",
        "total_deaths" : "0",
        "new_deaths" : "0",
        "total_cases_per_million" : "18.733",
        "new_cases_per_million" : "18.733",
        "total_deaths_per_million" : "0.0",
        "new_deaths_per_million" : "0.0",
        "total_tests" : "",
        "new_tests" : "",
        "total_tests_per_thousand" : "",
        "new_tests_per_thousand" : "",
        "new_tests_smoothed" : "",
        "new_tests_smoothed_per_thousand" : "",
        "tests_units" : "",
        "stringency_index" : "0.0",
        "population" : "106766.0",
        "population_density" : "584.8",
        "median_age" : "41.2",
        "aged_65_older" : "13.085",
        "aged_70_older" : "7.452",
        "gdp_per_capita" : "35973.781",
        "extreme_poverty" : "",
        "cvd_death_rate" : "",
        "diabetes_prevalence" : "11.62",
        "female_smokers" : "",
        "male_smokers" : "",
        "handwashing_facilities" : "",
    },
    .
    .
    .
},
.
.
.
</code></pre>

> Structure the program so that appropriate methods are used in a class called JSONParser.  Ensure good program structure by dividing the processing into separate methods for reading, writing and or analyzing the input data.  
