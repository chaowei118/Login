#ifndef PRO_FUNCTIONS_H_INCLUDED
#define PRO_FUNCTIONS_H_INCLUDED

#include <string>

struct Patient
{
    std::string Title;
    std::string Name;
    int Age;
    char Gender;
    int Ailment;
    int Ail_degree;
};

struct Doctor
{
    std::string Name;
    char Gender;
    int Quality;
};

struct Ailment
{
    std::string Name;
    int Ail_det_com;
    int Ail_tre_com;
    int Treatment;
};

void load_file(const std::string _filename);
void see_doctor(const Patient &pat);
void goto_hospital(int pat_num);
bool diagnose(const Patient &_pat,const Doctor &_doc);
bool tre_success(const Ailment &_ail,const Doctor &_doc,const Patient &_pat);
void Load_file(int argc, char *argv[]);



#endif // PRO_FUNCTIONS_H_INCLUDED
