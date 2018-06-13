#pragma once

#include <iostream>
#include <sstream>
#include <string>
//using namespace std;



class TestCase
{
    int PASSED = 0, FAILED = 0;
    std::string _name;
    std::ostream &_os;
    public:
    
        TestCase(std::string str,std::ostream& os):_name(str),_os(os){};
        
        template <typename T>
    	TestCase& check_equal(T x,T y){
    	    if(x == y){
    	        ++PASSED;
    	    }
    	    else{
    	        ++FAILED;//MyStrct(5) should equal MyStrct(5)!
    	        _os << _name << ": Failure in test #" <<std::to_string(PASSED+FAILED) << 
    	        ": "<< y <<" should equal " << x <<"!" << std::endl;
    	    }
    	    return *this;
    	}
    	
        template <typename T>
    	TestCase& check_different(T x,T y){
    	    if(x != y){
    	        ++PASSED;
    	    }
    	    else{
    	        _os << _name << ": Failure in test #" <<std::to_string(PASSED+FAILED) << 
    	        ": "<< y <<" should not equal " << x <<"!" << std::endl;
    	        ++FAILED;
    	    }
    	    return *this;    	    
    	}    
    	
/*    	template <typename A,typename B ,typename C ,typename D>
    	TestCase check_function(A (*foo)(const B), C x,D y){
    	    if(foo(x) == y){
    	        ++PASSED;
    	    }
    	    else{
    	        ++FAILED;
    	        _os << _name << ": Failure in test #" <<std::to_string(PASSED+FAILED) << 
    	        ": Function should return " << std::to_string(y) 
    	        << " but returned "<< std::to_string(foo(x)) <<"!" << std::endl;
    	    }
    	    return *this;
    	}*/
    	
    	//Needed this for sending lambda functions:
    	template <typename FUN ,typename C ,typename D>
    	TestCase& check_function(FUN foo, C x,D y){
    	    if(foo(x) == y){
    	        ++PASSED;
    	    }
    	    else{
    	        ++FAILED;
    	        _os << _name << ": Failure in test #" <<std::to_string(PASSED+FAILED) << 
    	        ": Function should return " << std::to_string(y) 
    	        << " but returned "<< std::to_string(foo(x)) <<"!" << std::endl;
    	    }
    	    return *this;
    	}
    	

    	
    	template <typename T>
    	TestCase& check_output(T x, std::string str){
    	    //std::ostringstream os >> x;
	        std::stringstream os;
            os << x;
            std::string x_str;
            os >>x_str;
    	     if(x_str == str){
    	        ++PASSED;
    	    }
    	    else{
    	        ++FAILED;
    	        _os << _name << ": Failure in test #" <<std::to_string(PASSED+FAILED) << 
    	        ": string value should be "<< str <<" but is " << x_str  << std::endl;
    	    }
    	    return *this;
    	}
    	
    	void print();
};

