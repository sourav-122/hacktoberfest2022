# Quiz Game using Python (A Copy of Kaun Banega Crorepati)

from threading import Timer
import os
import time
from turtle import clear


def trip():
    print("OOpps!TIme's Up")
t= Timer(10,trip)

q1='''1. Who Created C?  

A. Dennis Ritchie
B. Ken Thompson
C. Brian Kernighan
D. Bjarne Stroustrup '''

q2= '''2. Which of the following approach is used by C++?

A. Left-right
B. Right-left
C. Bottom-up
D. Top-down '''

q3= '''3. Which of the following is used for comments in C++?

 A./* comment */
 B. // comment */
 C. // comment
 D. both // comment or /* comment */ '''
q4= '''4. Which of the following is used to terminate the function declaration in C++?

A. ;
B. ]
C. ) 
D. :  '''
q5='''5. Which of the following is the correct syntax of including a user defined header files in C++?

A. #include [userdefined]
B. #include “userdefined”
C. #include <userdefined.h>
D> #include <userdefined> '''
q6='''6. Which of the following is not a type of Constructor in C++?

A. Default constructor
B. Parameterized constructor
C. Copy constructor
D. Friend constructor '''
q7=''' 7. Which of the following type is provided by C++ but not C?

a) double
b) float
c) int
d) bool '''
q8='''8. Identify the correct extension of the user-defined header file in C++?

A. .cpp
B. .hg
C. .h
D. .hf '''
q9='''9. goto can be classified into?

A. label
B. variable
C. operator 
D. function
'''
q10='''10. Which is more effective while calling the C++ functions?

A. call by object
B. call by pointer
C. call by value
D. call by reference '''

questions={q1:'A', q2:'C' , q3:'D' , q4 :'A' , q5:'B', q6:'D', q7:'D', q8:'C',q9:'A', q10:'D'}

print("-------------------- WELCOME TO KAUN BANEGA CROREPATI ---------------------")
amount_won = [1000,5000, 10000,
    50000, 160000,
   320000, 640000, 1250000, 2500000,
   5000000]
def play():
    score= 0
    balance= 0
    j=0
    q=""
    time.sleep(2)

    name= input("Enter Your Name: ")
    print('*****************************************************')
    
    localtime = time.localtime()
    result = time.strftime("%I:%M:%S %p", localtime)
    print("\t\tTIME: ",result)
    print("\nHello",name,"Welcome TO The C/C++ Quiz World")
    time.sleep(2)
    for i in questions:
        print()
        print(i)
        
        time.sleep(1.5)
        #t.start()
        ans= input(" \nEnter The Answer Of the Questions: (A/B/C/D) ").upper()
        print("\nChecking Your Answer")
        if(ans==questions[i]):
            time.sleep(1)
            print("\nYour Answer is Correct")
            score+= 1
            balance = amount_won[score-1]
            print(f" \nYou Got {balance} Rupees for this Question")
        else:
            time.sleep(1)
            print("\nYour Answer is Wrong!!!")
            print("\nCONGRATULATIONS!!YOU JUST WON ",balance,"Rs")
            print("\nByeeeee!Thanks for Playing ")
            exit(0)
        print('--------------------------------------------------')
        if(j<len(questions)):
            q= input("\nDo You Want to Exit The Quiz:(yes,no) ").lower()
            if(q=='yes'):
                break
            else:
                os.system('cls')
                continue
        
    print("\nCONGRATULATIONS!!YOU JUST WON ",balance,"Rupayee")
        
play()


