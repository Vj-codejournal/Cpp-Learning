#include <iostream>

using ProcessId = int;
using namespace std;

struct Process
{
    Process *previousProcess;
    Process *nextProcess;
    ProcessId id;
};

class Scheduler
{

    Process *head;
    Process *ptrTolast;
    int cnt= 0;

public:
    void Head()
    {
        head = new Process();
        head->previousProcess = nullptr;
        head->nextProcess = nullptr;
        ptrTolast = head;
    }
    /*
          adds process with id = pid to the end of the linked list
    */
    void MakeptrTolast()
    {  ptrTolast=head;
        while (ptrTolast->nextProcess != nullptr)
            ptrTolast = ptrTolast->nextProcess;
    }

    Process *add_process(ProcessId pid)
    {
        // code to add_process goes here
        cnt++;
        Process *addedptr = new Process();
        addedptr->id = pid;
        addedptr->nextProcess = nullptr;

        if (cnt==1)
  
        {
            
            Process *temp;
            temp = head;
            head = addedptr;
            ptrTolast = head;
            addedptr->previousProcess = nullptr;
            free(temp);
        }
        if (cnt == 2)
        {
            head->nextProcess = addedptr;
            addedptr->previousProcess = head;
            
        }
        
        else
            {
            MakeptrTolast();
            ptrTolast->nextProcess = addedptr;
            addedptr->previousProcess = ptrTolast;
            ptrTolast=ptrTolast->nextProcess;
            }
        return 0;
    }

    /*
          deletes process with id == pid
    */
    void delete_process(ProcessId pid)
    {
        // code to delete_process goes here
        Process* temp = head;
        while(temp->id!=pid)
        {
            temp = temp->nextProcess;
        }

        Process* prev_temp;
        Process* next_temp;
        MakeptrTolast();
        if(temp == head){
            head = head->nextProcess;
            head->previousProcess = nullptr;
            free(temp);
        }
          
        else if(temp == ptrTolast){
          prev_temp = head;
          while(prev_temp->nextProcess != temp)
            prev_temp = prev_temp->nextProcess;
          
           prev_temp->nextProcess=nullptr;
            free(temp);
        }
        else{
        prev_temp = head;
        next_temp= head;
          
        
        while(prev_temp->nextProcess != temp)
            prev_temp = prev_temp->nextProcess;
        
        
        while(next_temp->nextProcess != temp)
          next_temp = next_temp->nextProcess;
          
        next_temp = next_temp->nextProcess;
        next_temp = next_temp->nextProcess;

        prev_temp->nextProcess = temp->nextProcess;
        next_temp->previousProcess = temp->previousProcess;
        
        
        free(temp);
        }
    }

    /*
          add a process with id == childId after process with id == parentId
    */
    Process *fork(ProcessId process, ProcessId newId)
    {
        // code to fork process goes here
        Process* temp = head;
        
        Process* addedptr = new Process();

        while(temp->id!=process)
        {
            temp = temp->nextProcess;
        }

        if(temp->nextProcess == nullptr){
          add_process(newId);
        }
        else{
        Process* temp2 = temp;
        temp2 = temp2->nextProcess;

        temp->nextProcess=addedptr;
        addedptr->nextProcess = temp2;
        
        addedptr->id= newId;
        addedptr->previousProcess = temp;
        temp2->previousProcess = addedptr;
        }
        
        return 0;
    }

    void print_schedule()
    {
        // code to print_schedule goes here
        Process* temp = head;
        while(temp->nextProcess!=nullptr)
        {
            cout<<temp->id<<" ";
            temp = temp->nextProcess;
        }
        cout<<temp->id<<" "<<endl;
        
    }
};

enum Operations
{
    ADD_PROCESS,
    DELETE_PROCESS,
    FORK,
    PRINT_SCHEDULE,
};

int main()
{
    Scheduler s;
    s.Head();
    s.MakeptrTolast();
    int n;
    cin >> n;

    while (n--)
    {
        int operationInput;
        cin >> operationInput;

        Operations opId = static_cast<Operations>(operationInput);

        if (opId == ADD_PROCESS)
        {
            ProcessId newPid;
            cin >> newPid;
            s.add_process(newPid);
        }
        else if (opId == DELETE_PROCESS)
        {
            ProcessId toBeDeletedPid;
            cin >> toBeDeletedPid;
            s.delete_process(toBeDeletedPid);
        }
        else if (opId == FORK)
        {
            ProcessId pidToBeForked;
            ProcessId newPid;
            cin >> pidToBeForked;
            cin >> newPid;
            s.fork(pidToBeForked, newPid);
        }
        else if (opId == PRINT_SCHEDULE)
        {
            s.print_schedule();
        }
    }
}