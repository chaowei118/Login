//Author: Rookie118
//Program's Propose: A medical center's simulation
//Completion time: 2017-11-08

#ifndef PRO_FUNCTIONS_H_INCLUDED
#define PRO_FUNCTIONS_H_INCLUDED

#include <string>

struct Patient
{
    std::string Title;  //病人称呼
    std::string Name;
    int Age;
    char Gender;
    int Ailment;  //所得疾病
    int Ail_degree;  //疾病程度
};

struct Doctor
{
    std::string Name;
    char Gender;
    int Quality;  //医生水平
};

struct Ailment
{
    std::string Name;
    int Ail_det_com;  //疾病诊断复杂度
    int Ail_tre_com;  //疾病治疗复杂度
    int Treatment;
};

void load_file(const std::string _filename);
void see_doctor(const Patient &pat);
void goto_hospital(int pat_num);
bool diagnose(const Patient &_pat,const Doctor &_doc);
bool tre_success(const Ailment &_ail,const Doctor &_doc,const Patient &_pat);
void Load_file(int argc, char *argv[]);



#endif // PRO_FUNCTIONS_H_INCLUDED
