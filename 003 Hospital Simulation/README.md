# 003 Hospital Simulation
## 1. Functional Description
This program is to be implemented using procedural programming and process
patients through a medical center. But, this program is not supposed to be a sensible simulation of such a centre, and
does not comply with typical operating practices for such center.
  
The Medical Center runs on a strict quota system, and closes after seeing the number of Patients specified
as the command argument, or when there are no Patients left to see.
There is otherwise no sense of time in this program, so it’s possible every patient could see the same
doctor.
  
A summary of what happens to each patient will be passed to whatever file is specified on the command line as the Output-file. 
Besides, the content of data files will be output in a sensible format.  

- The patients will be treated on a one by one basis.  
- Each patient will need to see a randomly chosen doctor of the same gender. If there is no doctor of
the same gender, the patient leaves with their ailment unresolved.  
- The doctors will attempt to diagnose the correct ailment, with the percentage change of doing. 
The percentage is related with the doctor’s quality, the ailment degree, and the ailment determination
complexity.  
- If the doctor fails to identify the correct ailment, the doctor will guess at the ailment, equally likely
to specify any ailment including the correct one.  
- If a doctor determines that the patient has a particular ailment they will apply the treatment
associated with that ailment.  
- The chance of the treatment working will be related with the doctor’s quality and
the ailment treatment complexity. If it’s the wrong treatment, the chance of it working will be
25% of the chance when using the correct treatment.   
- Once given a treatment the patient leaves, whether the treatment is successful or not.  

## 2. File Specification
If a given data file has an incorrectly formatted line, the problem will be reported and that line will be ignored.
There are four data files in this program:
  
(1) Patients.txt: No more than 100 entries.  
Title,Name,Age,Gender,Ailment,Ailment degree.  
Example:  
Ms,Alice Anteater,25,F,3,100.  
Mr,Bob Badger,37,M,2,50.  
Cpl,Carol Carrot,45,F,2,75.  
,Dan Digger,30,M,1,20.  
Dr,Ernie Edwards,50,M,3,75.  
The Age, Ailment and Ailment degree are all integers, but the Ailment degree is a percentage in the range
1 to 100. Gender is a single character. Although the title can be empty, there must be a name. The Ailment corresponds to the Ailments listed in the Ailments.txt.
The higher the Ailment degree, the worse case of that Ailment the patient has. The higher it is, the easier it is recognized.

(2) Doctors.txt: No more than 10 entries.  
Name,Gender,Quality.  
Example:    
Boris Barn-Owl,M,77.  
Ernie Edwards,M,60.  
Frankie Fisher,M,75.  
Geraldine Gardner,F,73.  
Henrietta Helpful,F,80.  
The name cannot be empty. Gender is a single character. The quality is a percentage in the range 1 to 100.  

(3) Ailments.txt: No more than 20 entries.  
Name,Ailment determination complexity,Ailment treatment complexity,Treatment.  
Example:  
Dizziness,20,70,1.  
Headache,5,5,3.  
Broken bone,5,25,2.    
Ailment determination complexity and Ailment treatment complexity
are percentages in the range 1 to 100. The lower Ailment determination
complexity, the easier it is to recognize the ailment. The higher Ailment treatment complexity, the harder it is to treat the ailment successfully.
The Treatment corresponds to the Treatments listed in the Treatments.txt.   

(4) Treatments.txt: No more than 10 entries.  
Name.  
Example:   
Bed rest.  
Plaster cast.  
Panadol.  
Antibiotics.  
Miscelleneous Medicine.  

The Output-file will include the doctor seen, the ailment diagnosed, the treatment, and whether the treatment was successful.

## 3. How to run this program
Using CodeBlocks software to creat a project which includes main.cpp, imple_functions.cpp and pro_functions.h, then building and using command lines to pass arguments for running.
