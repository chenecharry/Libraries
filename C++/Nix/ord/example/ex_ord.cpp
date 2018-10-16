#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>

#include "./ord.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;


int main(){
    cout << "========================================\n";
    cout << "testing vector discovery\n\n";
    vector<string> vec_str{"zero","one","two","three","four","five"};
    vector<char>   vec_char{'v','a','r','c','h','a','r'};

    char v1[] = "var1";
    char v2[] = "var2";
    char v3[] = "var3";
    char v4[] = "var4";
    vector<char*> vec_chara{v1, v2, v3, v4};

    vector<int>   vec_int{0,1,2,3,4,5,6};

    cout << ord::join(vec_str) << endl;
    cout << ord::join(vec_char) << endl;
    cout << ord::join(vec_chara) << endl;
    cout << ord::join(vec_int) << endl;

    std::string three = "three";
    cout << "true  => " << ord::has(three, vec_str) << endl;
    cout << "true  => " << ord::has("two", vec_str) << endl;
    cout << "false = " << ord::has("twenty", vec_str) << endl;

    cout << "true  => " << ord::has(5, vec_int) << endl;
    cout << "false = " << ord::has(7, vec_int) << endl;

    // ----------------------------------------------------------------
    cout << "========================================\n";
    cout << "testing regex\n\n";
    vector<string> emails {
        "first.last@subdomain.domain.com",
        "realuser@gmail.com",
        "trap@attack.hack.info"
    };

    cout << "false email = " << ord::matchOne("[\\w\\d_]*@[\\w\\d_]*", emails) << endl;
    // that failed because it does not match any one email start to finish
    cout << "true  email = " << ord::matchOne("^([\\w\\d_]*(\\.?)){1,2}@([\\w\\d_]*\\.){1,2}[\\w\\d_]*$", emails) << endl;;
    // this one matches the first email start to finish so it replies true


    cout << "true email  = " << ord::scanOne("[\\w\\d_]*@[\\w\\d_]*", emails) << endl;
    // this time the partial email returns true because the regex matches at least a portion
    // of one of the elements in the array.

    std::string found_email =  ord::retScans("^([\\w\\d_]*(\\.?)){1,2}@([\\w\\d_]*\\.){1,2}[\\w\\d_]*$", emails)[0];
    cout << found_email << endl;
    emails[0] = "new.appended@email.com";
    cout << found_email << endl; // passing of data gives you a deep copy from the *iterator

    cout << ord::retScans("[\\w\\d_]*@[\\w\\d_]*", emails)[2] << endl;


    cout << "========================================\n";
    cout << "testing map discovery\n\n";

    std::map<string, vector<string>> omap = {   {"first", {"1-one","1-two","1-three"}},
                                                {"second",{"2-one","2-two","2-three"}}
                                            };

    std::unordered_map<std::string,std::string> umap1 ={{ "hash1", "AAAA"},
                                                        { "hash2", "BBBB"},
                                                        { "hash3", "CCCC"},
                                                        { "hash4", ""}
                                                       };

    std::unordered_map<std::string,std::string> umap2 = {{ "AAAA", "1111"},
                                                         { "BBBB", "2222"},
                                                         { "CCCC", "3333"}
                                                        };


    cout << ord::join(ord::keys(umap1)) << endl;
    // notice that the key hash4 is present becaused it list all of them
    // however hash4 really doesn't exist becaues it has no data so

    cout << "true  => " << ord::hasKey("hash2",umap1) << endl;
    cout << "False = " << ord::hasKey("hash4",umap1) << endl; // ret false sense hash4 contains nothing
    cout << "False = " << ord::hasKey("no key",umap1) << endl;

    cout << "true  => " << ord::has("1-two", omap.at("first")) << endl;
    cout << "False = " << ord::has("2-two", omap.at("first")) << endl;
    
        

    cout << ord::join(ord::keys<std::string, std::vector<std::string>>(omap)," <> ") << endl;
    cout << ord::join(ord::keys(omap)," <> ") << endl;

    cout << ord::join(ord::keyValues<std::string, std::string>(umap1)," <> ", true) << endl;

    cout << "true  => " << ord::scanOne("(con)", ord::keys(omap)) << endl;

    ord::relational_copy(umap1, umap2,"hash3", "C-EXT" ); 
    // find umap1 key's value as a key in umap 2 and make it a value for a new key "C-EXT" 

    cout << ord::join(ord::keys(umap1)) << endl;

    cout << umap1.at("C-EXT") << endl;

    cout << "========================================\n";
    cout << "generators\n";

    cout << ord::join(ord::range(0,10), " - ") << endl;

    cout << "12345" << ord::ditto("0",5) << endl;


    return 0;
}   