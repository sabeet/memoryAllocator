#include<iostream>
#include<string>

using namespace std;

class process{ //create a process class
    public:
        string process_name;
        int starting_address;
        int ending_address;

        string get_process_name(){return process_name;}
        void set_process_name(string process_name){this->process_name=process_name;}

        int get_starting_address(){return starting_address;}
        void set_starting_address(int starting_address){this->starting_address=starting_address;}

        int get_ending_address(){return ending_address;}
        void set_ending_address(int ending_address){this->ending_address=ending_address;}
};

class bitArray{ //this class will simulate the bits for the processes to use
    public:
        string owner = "NULL";
        bool is_free = true;

        string get_owner(){return owner;}
        void set_owner(string owner){this->owner=owner;}

        bool get_is_free(){return is_free;}
        void set_is_free(bool is_free){this->is_free=is_free;}
};

class blockForCompaction{ //we shall be using this class to load data onto the bit array for compaction
    public:
        string block_name;
        int block_starting_address;
        int block_ending_address;

        string get_block_name(){return block_name;}
        void set_block_name(string block_name){this->block_name=block_name;}

        int get_block_starting_address(){return block_starting_address;}
        void set_block_starting_address(int block_starting_address){this->block_starting_address=block_starting_address;}

        int get_block_ending_address(){return block_ending_address;}
        void set_block_ending_address(int block_ending_address){this->block_ending_address=block_ending_address;}
};

int main(){

    //initialize bit array class array to simulate a "line" of empty data
    int valueFromArg = 70;
    bitArray ba[valueFromArg];
    string input1,input2;
    int process_incrementer = 2;
    process p[process_incrementer];

    //initialize P0
    p[-1].set_process_name("NULL");
    p[-1].set_starting_address(0);
    p[-1].set_ending_address(0);
    p[0].set_process_name("NULL");
    p[0].set_starting_address(0);
    p[0].set_ending_address(0);

    //set up the bit array
    for(int i=0; i <= valueFromArg; i++){
        //set up the values for each bit
        ba[i].set_owner("NULL"); // cout check valid
        ba[i].set_is_free(true); // cout check valid
    }

    //this is surprisingly tough
    //allocate process into bit array from user input
    //assume just two input
    //input sample RQ P0 5 B
    //             RQ P1 15 B

    cout << "allocator>";
    for(int i=0; i<sizeof(p); i++){
        cin >> input1 >> input2;
        p[i].set_process_name(input1);
        p[i].set_starting_address(p[i-1].get_ending_address());
        p[i].set_ending_address(p[i-1].get_ending_address() + stoi(input2) -1);
        process_incrementer++;

    }
    

return 0;
}