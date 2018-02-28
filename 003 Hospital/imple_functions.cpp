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
        throw(string("Invalid file"));  //文件无法正常打开，异常抛出
    }

    string strtemp;  //字符串暂存变量
    int fcomma_pos;  //文件中第一个逗号位置
    int i = 0;  //记录读取次数
    int line_count = 0;
    stringstream sstream;  //字符串流变量，起到中转作用
    while(getline(inFlie, strtemp))  //从文件中读取一行数据存放到strtemp中
    {

        ++line_count;
        int flag_per = strtemp.find('.');  //找到此行字符串的句号位置
        if(flag_per == string::npos)  //如果没找到句号，则认为此行是无效行
        {
            cout << "This line " << line_count << " of the " << _filename << " is incorrectly! It will be ignored!" << endl;
            continue;
        }
        if(_filename == "Patients.txt")
        {
            int blank_pos = strtemp.find(' ');  //找到此行第一个空格位置
            while(blank_pos != string::npos)
            {
                strtemp = strtemp.erase(blank_pos, 1);  //将字符串中的空格去掉
                blank_pos = strtemp.find(' ');
            }
            int com_pos = strtemp.find(',');  //找到此行第一个逗号的位置
            fcomma_pos = com_pos;
            while(com_pos != string::npos)
            {
                strtemp = strtemp.replace(com_pos, 1, 1, ' ');  //将字符串中的','用空格代替
                com_pos = strtemp.find(',');
            }
            int per_pos = strtemp.find('.');  //找到此行第一个句号的位置
            while(per_pos != string::npos)
            {
                strtemp = strtemp.replace(per_pos, 1, 1, ' ');  //将字符串中的'.'用空格代替
                per_pos = strtemp.find('.');
            }
            sstream << strtemp;  //将字符串导入到字符串流中
            pat_count++;
            if(fcomma_pos == 0)  //没有称呼的人名用空格代替
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

    for(int j = 0; j < i; j++)  //输出读取的文件内容
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

bool diagnose(Patient &_pat, Doctor &_doc)  //诊断函数
{
    double dia_probablity;  //诊断成功率
    dia_probablity = ((double)_doc.Quality/100.0)*2.0*((double)_pat.Ail_degree/100.0)*((double)(100-ailment[_pat.Ailment-1].Ail_det_com)/100.0);

    srand((unsigned)time(NULL));  //按时间产生随机化种子
    if((int)(dia_probablity*100) > rand()%100)  //按照概率判断诊断是否成功
        return 1;
    else
        return 0;

}

bool tre_success(Ailment &_ail, Doctor &_doc, Patient &_pat)  //治疗函数
{
    double tre_probablity;  //治疗成功率
    if(_ail.Name == ailment[_pat.Ailment-1].Name)  //判断病人所得疾病和医生诊断疾病是否相同
    {
        tre_probablity = ((double)_doc.Quality/100.0)*2.0*((double)(100-_ail.Ail_tre_com)/100.0);
    }
    else  //不相同则治疗成功率减少75%
    {
        tre_probablity = ((double)_doc.Quality/100.0)*2.0*((double)(100-ailment[_pat.Ailment-1].Ail_tre_com)/100.0)*0.25;
    }

    srand((unsigned)time(NULL));  //按时间产生随机化种子
    if((int)(tre_probablity*100) > rand()%100)  //按照概率判断诊断是否成功
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
        i = rand()%doc_count;  //随机选择医生进行诊断
        if(_pat.Gender == doctor[i].Gender)  //直到病人性别和医生性别相同
        {
            break;
        }
        count++;
    }
    if(count == doc_count)  //没有相同性别的则无法诊断
    {
        if(_pat.Title == " ")
            outFile << "There is no doctor of the same gender for " << _pat.Name << endl << endl;
        else
            outFile << "There is no doctor of the same gender for " << _pat.Title << '.' << _pat.Name << endl << endl;
        return;
    }

    bool flag_dia_successful;  //诊断成功标志
    bool flag_tre_successful;  //治疗成功标志
    Ailment guess_ail;  //诊断不成功则猜测疾病名
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
    if(flag_dia_successful)  //诊断结果输出到文件
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
    for(int i = 1; i < argc-1; i++)  //命令行总共有6个参数，第2个到第5个参数为文本文件名
    {
        try
        {
            load_file(argv[i]);  //读取文件内容
        }
        catch(std::string err)  //异常处理，防止文件名输错
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
    else  //防止病人数量输错，并限制接诊人数
    {
        cout << "The number of patients should be greater than 0 and not be greater than " << pat_count <<" !" << endl;
        cout << "Please input correct number: ";
        cin >> pat_num;
        for(int i = 0; i < pat_num; i++)
            see_doctor(patient[i]);
    }
}
