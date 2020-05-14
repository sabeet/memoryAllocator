#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class process{
    public:
        string process_name;
        int start_address;
        int end_address;

        string get_process_name(){return process_name;}
        void set_process_number(string process_number){this->process_name=process_number;}

        int get_start_address(){return start_address;}
        void set_start_address(int start_address){this->start_address=start_address;}

        int get_end_address(){return end_address;}
        void set_end_address(int end_address){this->end_address=end_address;}

};

int main(int argc, char *argv[]){ //argc gets the number of args || argv gets the strings

    //obtain the memory size total

    int max_bit_array_size = stoi(argv[1]); //string to int conversion
    cout << "memory total is " << max_bit_array_size << endl;

    string command, process_num, block_size, mem_management;
    cout << "allocator>";
    cin >> command >> process_num >> block_size >> mem_management;

    while(command != "QUIT"){

        //example input: RQ P0 10101 B 

        if(command.substr(0,2) == "RQ"){                //grabNumbers only
            cout << "" << process_num << endl;  //grab p_num from here
            
        }

        else if(command.substr(0,2) == "RL"){
            cout << "" << process_num << endl; //grab p_num from here
                   
        }

        else if(command.substr(0,4) == "STAT"){
            cout << "display stat here" << endl;
            
        }

        else if(command.substr(0,1) == "C"){
            cout << "attempting compaction" << endl;
            
        }

        //going to the next input
        cout << "allocator>";
        cin >> command >> process_num >> block_size >> mem_management;


    }

    if(command == "QUIT"){
        cout << "You quit the program" << endl;
        exit(0);
    }

    return 0;
}