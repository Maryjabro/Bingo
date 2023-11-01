#include "BingoCard.h"


BingoCard::BingoCard(int size) {

    board_size = size;

    board = new vector<vector<int>*>;
    marked = new vector<vector<bool>*>;

    for (int i = 0; i < board_size; i++) {
        vector<int>* row = new vector<int>(board_size, 0);
        vector<bool>* markedRow = new vector<bool>(board_size, false);
        board->push_back(row);
        marked->push_back(markedRow);
    }
    fill();
}


string BingoCard::toString() {
    
    
        stringstream print;

    for (int i = 0; i < board_size; i++) {
        for (int n = 0; n < board_size; n++) {
            if (marked->at(i)->at(n)) {
                print <<  "|("<<setw(3)<<board->at(i)->at(n) << " )|";
            } else {
                print<<"| "<<setw(3)<< board->at(i)->at(n) << "  |";
            }
        }
        print << endl;
    }

    return print.str();
}


void BingoCard::call(int num) {
    cout<<"Calling "<<num<<endl;
    for(int i =0;i<board_size;i++){
        for(int n=0;n<board_size;n++){
            if((board->at(i)->at(n))==num){
                marked->at(i)->at(n)=true;
                
            }
            
        }
        
    }
}


void BingoCard::clearBoard() {
    for(int i =0;i<board_size;i++){
        for(int n=0;n<board_size;n++){
                marked->at(i)->at(n)=false;
        }
        
    }    
    
}


void BingoCard::fill() {
	vector<int> range{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for (int col = 0; col < board_size; col++) {
		random_shuffle(range.begin(), range.end(), badRand);
		for (int row = 0; row < board_size; row++) {
			board->at(row)->at(col) = range.at(row) + (15 * col);
			marked->at(row)->at(col) = false;
		}
	}
}


bool BingoCard::checkVertical() {

    for(int col = 0;col<board_size;col++){
        bool checked=true;
        for(int row=0;row<board_size;row++){
            if(marked->at(row)->at(col)==false){
                checked=false;
                break;
            }
            
        }
        if(checked==true){
            return true;
        }
    }
    return false;
    
    
}

bool BingoCard::checkHorizontal() {
    for (int row = 0; row < board_size; row++) {
        bool checked = true;
        for (int col = 0; col < board_size; col++) {
            if (marked->at(row)->at(col)==false) {
                checked = false;
                break;
            }
        }
        if (checked==true) {
            return true; 
        }
    }
    return false;
}


bool BingoCard::checkDiagonal() {

    bool diagonal1= true;
    for (int i = 0; i < board_size; i++) {
        if (marked->at(i)->at(i)==false) {
            diagonal1 = false;
            break;
        }
    }
    if (diagonal1) {
        return true; 
    }


    bool diagonal2 = true;
    for (int i = 0; i < board_size; i++) {
        if (marked->at(i)->at(board_size - 1 - i)==false) {
            diagonal2 = false;
            break;
        }
    }
    if (diagonal2==true) {
        return true; 
    }

    return false;
}   
    
bool BingoCard::checkBingo() {
    if(checkVertical()|| checkHorizontal()||checkDiagonal()){
        
        return true;
    }
    else{
        return false;
    }

    
}


int randomfunc(int j) {
	return rand() % j;
}

int badRand(int j) {
	return 100 % j;
}
