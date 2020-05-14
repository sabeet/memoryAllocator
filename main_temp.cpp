//Sabeet Chowdhury
//CS 340 Operating Systems || Queens College || Spring 2020
//Professor John Svadlenka

#include <iostream>
#include <string>
using namespace std;

class Process{
    private:
        string process_number;
        int start_memory_address;
        int end_memory_address;
        //bool owns_space;

    public:
        /* skeleton
        int get_(){return ;}
        void set_(int ){this->=;}
        */
        string get_process_number(){return process_number;}
        void set_process_number(string process_number){this->process_number=process_number;}

        int get_start_memory_address(){return start_memory_address;}
        void set_start_memory_address(int start_memory_address){this->start_memory_address=start_memory_address;}

        int get_end_memory_address(){return end_memory_address;}
        void set_end_memory_address(int end_memory_address){this->end_memory_address=end_memory_address;}

        //bool get_owns_space(){return owns_space;}
        //void set_owns_space(bool owns_space){this->owns_space=owns_space;}
        
};

class addressBit{
    private:
        int bitAddress;
        string ownedBy;
        bool isFree = true;

    public:
        int get_bit_address(){return bitAddress;}
        void set_bit_address(int bitAddress){this->bitAddress=bitAddress;}

        string get_owned_by(){return ownedBy;}
        void set_owned_by(string ownedBy){this->ownedBy=ownedBy;}

        bool get_is_free(){return isFree;}
        void set_is_free(bool isFree){this->isFree=isFree;}

};


int main(int argc, char *argv[]){

    int initiate_max_size;

    addressBit ab[255];
    for(int i = 0; i<= 255; i++){
        ab[i].set_bit_address(i);
        ab[i].set_is_free(true);
        
    }

    //set user input into these thing
    Process process;
    process.set_process_number("P1"); 
    process.set_start_memory_address(0); 
    process.set_end_memory_address(70);

    Process process2;
    process2.set_process_number("P2"); 
    process2.set_start_memory_address(90); 
    process2.set_end_memory_address(150);
    
    //for loop here does sets value onto bit
    for(int i = process.get_start_memory_address(); i <= process.get_end_memory_address(); i++){

        ab[i].set_bit_address(i);
        ab[i].set_is_free(false);
        ab[i].set_owned_by(process.get_process_number());

    }

    for(int i = process2.get_start_memory_address(); i <= process2.get_end_memory_address(); i++){

        ab[i].set_bit_address(i);
        ab[i].set_is_free(false);
        ab[i].set_owned_by(process2.get_process_number());

    }

    cout << "Address : " << ab[2].get_bit_address() << endl;
    cout << "Is is free? : " << ab[2].get_is_free() << endl;
    cout << "It's owned by : " << ab[2].get_owned_by() << endl;

    cout << endl;

    cout << "Address : " << ab[72].get_bit_address() << endl;
    cout << "Is is free? : " << ab[72].get_is_free() << endl;
    cout << "It's owned by : " << ab[72].get_owned_by() << endl;

    //

    //find free bits
    
    for(int i= 0; i <= 255; i++){
        if(ab[i].get_is_free() != true){
            //load those bits addresses here
            cout << ab[i].get_bit_address() << " is free" << endl;
        }
    }
    
    //cout << "Allocator>";
    //use getline here

return 0;
}