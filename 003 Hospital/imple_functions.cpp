//Author: Rookie118
//Program's Propose: A medical center's simulation
//Completion time: 2017-11-08

#include "pro_functions.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <time.h>

using namespace std;

Patient patient[100];
Doctor doctor[10];
Ailment ailment[20];
string treatment[10];
int pat_count = 0;
int doc_count = 0;
int ail_count = 0;

void load_file(string _filename)
{

    ifstream inFlie;
    inFlie.open(_filename);
    if(!inFlie.is_open())
    {
        throw(string("Invalid file"));
    }

    string strtemp;
    int fcomma_pos;
    int i = 0;
    int line_count = 0;
    stringstream sstream;
    while(getline(inFlie, strtemp))
    {

        ++line_count;
        int flag_per = strtemp.find('.');
        if(flag_per == string::npos)
        {
            cout << "This line " << line_count << " of the " << _filename << " is incorrectly! It will be ignored!" << endl;
            continue;
        }
        if(_filename == "Patients.txt")
        {
            int blank_pos = strtemp.find(' ');
            while(blank_pos != string::npos)
            {
                strtemp = strtemp.erase(blank_pos, 1);  //将字符串中的空格去掉
                blank_pos = strtemp.find(' ');
            }
            int com_pos = strtemp.find(',');
            fcomma_pos = com_pos;
            while(com_pos != string::npos)
            {
                strtemp = strtemp.replace(com_pos, 1, 1, ' ');  //将字符串中的','用空格代替
                com_pos = strtemp.find(',');
            }
            int per_pos = strtemp.find('.');
            while(per_pos != string::npos)
            {
                strtemp = strtemp.replace(per_pos, 1, 1, ' ');  //将字符串中的'.'用空格代替
                per_pos = strtemp.find('.');
            }
            sstream << strtemp; //将字符串导入的流中
            pat_count++;
            if(fcomma_pos == 0)
            {
                patient[i].Title = ' ';
                sstream >> patient[i].Name;
                sstream >> patient[i].Age;
                sstream >> patient[i].Gender;
                sstream >> patient[i].Ailment;
                sstream >> patient[i].Ail_degree;
                ++i;
            }
            else
            {
                sstream >> patient[i].Title;
                sstream >> patient[i].Name;
                sstream >> patient[i].Age;
                sstream >> patient[i].Gender;
                sstream >> patient[i].Ailment;
                sstream >> patient[i].Ail_degree;
                ++i;
            }
        }
        else
        {
            int blank_pos = strtemp.find(' ');
            while(blank_pos != string::npos)
            {
                strtemp = strtemp.erase(blank_pos, 1);  //将字符串中的空格去掉
                blank_pos = strtemp.find(' ');
            }
            int com_pos = strtemp.find(',');
            while(com_pos != string::npos)
            {
                strtemp = strtemp.replace(com_pos, 1, 1, ' ');  //将字符串中的','用空格代替
                com_pos = strtemp.find(',');
            }
            int per_pos = strtemp.find('.');
            while(per_pos != string::npos)
            {
                strtemp = strtemp.replace(per_pos, 1, 1, ' ');  //将字符串中的'.'用空格代替
                per_pos = strtemp.find('.');
            }
            sstream << strtemp;
            if(_filename == "Doctors.txt")
            {
                sstream >> doctor[i].Name;
                sstream >> doctor[i].Gender;
                sstream >> doctor[i].Quality;
                ++i;
                doc_count++;
            }
            if(_filename == "Ailments.txt")
            {
                sstream >> ailment[i].Name;
                sstream >> ailment[i].Ail_det_com;
                sstream >> ailment[i].Ail_tre_com;
                sstream >> ailment[i].Treatment;
                ++i;
                ail_count++;
            }
            if(_filename == "Treatments.txt")
            {
                sstream >> treatment[i];
                ++i;
            }
        }
    }
    inFlie.close();

    for(int j = 0; j < i; j++)
    {
        if(_filename == "Patients.txt")
        {
            cout << "Patient" << j+1 << " data:" << endl;
            cout << patient[j].Title << " " << patient[j].Name << " " << patient[j].Age << " " << patient[j].Gender
                 <<  " " << patient[j].Ailment << " " << patient[j].Ail_degree << endl;
        }
        if(_filename == "Doctors.txt")
        {
            cout << "Doctor" << j+1 << " data:" << endl;
            cout << doctor[j].Name << " " << doctor[j].Gender << " " << doctor[j].Quality << endl;
        }
        if(_filename == "Ailments.txt")
        {
            cout << "Ailment" << j+1 << " data:"  << endl;
            cout << ailment[j].Name << " " << ailment[j].Ail_det_com << " " << ailment[j].Ail_tre_com
                 << " " << ailment[j].Treatment << endl;
        }
        if(_filename == "Treatments.txt")
        {
            cout << "Treatment" << j+1 << " data:" << endl;
            cout << treatment[j] << " " << endl;
        }

    }
}

bool diagnose(Patient &_pat, Doctor &_doc)
{
    double dia_probablity;
    dia_probablity = ((double)_doc.Quality/100.0)*2.0*((double)_pat.Ail_degree/100.0)*((double)(100-ailment[_pat.Ailment-1].Ail_det_com)/100.0);

    srand((unsigned)time(NULL));
    if((int)(dia_probablity*100) > rand()%100)
        return 1;
    else
        return 0;

}

bool tre_success(Ailment &_ail, Doctor &_doc, Patient &_pat)
{
    double tre_probablity;
    if(_ail.Name == ailment[_pat.Ailment-1].Name)
    {
        tre_probablity = ((double)_doc.Quality/100.0)*2.0*((double)(100-_ail.Ail_tre_com)/100.0);
    }
    else
    {
        tre_probablity = ((double)_doc.Quality/100.0)*2.0*((double)(100-ailment[_pat.Ailment-1].Ail_tre_com)/100.0)*0.25;
    }

    srand((unsigned)time(NULL));
    if((int)(tre_probablity*100) > rand()%100)
        return 1;
    else
        return 0;

}

void see_doctor(Patient &_pat)
{
    ofstream outFile;
    outFile.open("Output-file.txt", ios_base::out|ios_base::app);

    int i;
    int count = 0;
    srand((unsigned)time(NULL));

    while(count < doc_count)
    {
        i = rand()%doc_count;
        if(_pat.Gender == doctor[i].Gender)
        {
            break;
        }
        count++;
    }
    if(count == doc_count)
    {
        if(_pat.Title == " ")
            outFile << "There is no doctor of the same gender for " << _pat.Name << endl << endl;
        else
            outFile << "There is no doctor of the same gender for " << _pat.Title << '.' << _pat.Name << endl << endl;
        return;
    }

    bool flag_dia_successful;
    bool flag_tre_successful;
    Ailment guess_ail;
    flag_dia_successful = diagnose(_pat, doctor[i]);
    if(flag_dia_successful)
    {
        flag_tre_successful = tre_success(ailment[_pat.Ailment-1], doctor[i], _pat);
    }
    else
    {
        guess_ail = ailment[rand()%ail_count];
        flag_tre_successful = tre_success(guess_ail, doctor[i], _pat);
    }

    string success;
    if(flag_dia_successful)
    {
       if(flag_tre_successful)
       {
           success = "Successful";
       }
       else
       {
           success = "Unsuccessful";
       }
       if(_pat.Title == " ")
       {

           outFile << "Patient: " << _pat.Name << "   " << "Doctor: "<< doctor[i].Name << "   "
                   << "Diagnose: " << ailment[_pat.Ailment-1].Name << "   "
                   << "Treatment: "<< treatment[ailment[_pat.Ailment-1].Treatment-1] << "   " << "Result: " << success << endl;
           outFile << endl;
       }
       else
       {

           outFile << "Patient: " <<_pat.Title << '.' << _pat.Name << "   " << "Doctor: " << doctor[i].Name << "   "
                   << "Diagnose: " << ailment[_pat.Ailment-1].Name << "   "
                   << "Treatment: " << treatment[ailment[_pat.Ailment-1].Treatment-1] << "   " << "Result: " << success << endl;
           outFile << endl;
       }
    }
    else
    {
       if(flag_tre_successful)
       {
           success = "Successful";
       }
       else
       {
           success = "Unsuccessful";
       }
       if(_pat.Title == " ")
       {

           outFile << "Patient: " << _pat.Name << "   " << "Doctor: "<< doctor[i].Name << "   "
                   << "Diagnose: " << ailment[_pat.Ailment-1].Name << "   "
                   << "Treatment: "<< treatment[ailment[_pat.Ailment-1].Treatment-1] << "   " << "Result: " << success << endl;
           outFile << endl;
       }
       else
       {

           outFile << "Patient: " <<_pat.Title << '.' << _pat.Name << "   " << "Doctor: " << doctor[i].Name << "   "
                   << "Diagnose: " << ailment[_pat.Ailment-1].Name << "   "
                   << "Treatment: " << treatment[ailment[_pat.Ailment-1].Treatment-1] << "   " << "Result: " << success << endl;
           outFile << endl;
       }
    }
    outFile.close();
}


void Load_file(int argc, char *argv[])
{
    for(int i = 1; i < argc-1; i++)
    {
        try
        {
            load_file(argv[i]);
        }
        catch(std::string err)
        {
                std::cout << "Could not open the file " << argv[i] << " !" <<std::endl;
                std::cout << "Please input correct file name: ";
                std::cin >> argv[i];
                load_file(argv[i]);
                continue;
        }
    }
}

void goto_hospital(int pat_num)
{
    if(pat_num <= pat_count && pat_num > 0)
    {
        for(int i = 0; i < pat_num; i++)
            see_doctor(patient[i]);
    }
    else
    {
        cout << "The number of patients should be greater than 0 and not be greater than " << pat_count <<" !" << endl;
        cout << "Please input correct number: ";
        cin >> pat_num;
        for(int i = 0; i < pat_num; i++)
            see_doctor(patient[i]);
    }
}
