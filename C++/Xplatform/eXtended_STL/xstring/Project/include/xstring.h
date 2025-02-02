#pragma once
#pragma warning (disable : 26444) // allow anynomous objects

/*
* Copyright[2019][Joel Leagues aka Scourge]
* Scourge /at\ protonmail /dot\ com
* www.Radicalware.com
* https://www.youtube.com/channel/UCivwmYxoOdDT3GmDnD0CfQA/playlists
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http ://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include<string>
#include<vector>
#include<utility>
#include<regex>
#include<functional> 
#include<algorithm>
#include<locale>
#include<memory>
#include<initializer_list>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<type_traits>

#include "re2/re2.h"

#include "Color.h"
#include "xvector.h"

namespace rxm {
    using namespace std::regex_constants;
    using type = syntax_option_type;
}

class xstring : public std::string
{
    using ull = unsigned long long;
public:
    static const xstring static_class;
    using std::string::basic_string;

    xstring(std::initializer_list<char> lst) : std::string(std::move(lst)) {};
    xstring(const std::string& str) : std::string(str) {};
    xstring(std::string&& str) noexcept : std::string(std::move(str)) {};
    xstring(size_t repeat, const char chr) : std::string(repeat, chr) {};
    xstring(const char chr);
    xstring(const char* chrs);
    xstring(const unsigned char* chrs);

    // operator=(&&) tests positive for moving in the examples

    void operator+=(const char chr);
    xstring operator+(const char chr);
    void operator+=(const char* chr);
    xstring operator+(const char* chr);
    void operator+=(const unsigned char* chr);
    xstring operator+(const unsigned char* chr);

    void operator+=(const std::string& str);
    xstring operator+(const std::string& str);
    void operator+=(std::string&& str);
    xstring operator+(std::string&& str);

    const char& At(size_t Idx) const;
    char& At(size_t Idx);

    size_t Size() const;

    void Print() const;
    void Print(int num) const;
    void Print(const xstring& front, const xstring& end = "") const;
    void Print(const char chr1, const char chr2 = ' ') const;
    void Print(const char* chr1, const char* chr2 = "") const;

    std::string  ToStdString() const;
    std::wstring ToStdWString() const;

    xstring ToUpper() const;
    xstring ToLower() const;

    xstring operator*(int total) const;
    void operator*=(int total);

    xstring Remove(const char val) const;

    xstring Reverse() const;
    // =================================================================================================================================
    
    xvector<xstring> Split(size_t loc) const;
    xvector<xstring> Split(const std::regex& rex) const;
    xvector<xstring> Split(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    xvector<xstring> Split(const char splitter, rxm::type mod = rxm::ECMAScript) const;

    xvector<xstring> InclusiveSplit(const std::regex& rex, bool single = true) const;
    xvector<xstring> InclusiveSplit(const xstring& splitter, rxm::type mod = rxm::ECMAScript, bool single = true) const;
    xvector<xstring> InclusiveSplit(const char* splitter, rxm::type mod = rxm::ECMAScript, bool aret = true) const;
    xvector<xstring> InclusiveSplit(const char splitter, rxm::type mod = rxm::ECMAScript, bool aret = true) const;

    //// =================================================================================================================================
    //   match is based on regex_match
    bool Match(const std::regex& rex) const;
    bool Match(const re2::RE2& rex) const;
    bool Match(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool Match(const char* str, rxm::type mod = rxm::ECMAScript) const;

    bool MatchLine(const std::regex& rex) const;
    bool MatchLine(const re2::RE2& rex) const;
    bool MatchLine(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool MatchLine(const char* str, rxm::type mod = rxm::ECMAScript) const;

    bool MatchAllLines(const std::regex& rex) const;
    bool MatchAllLines(const re2::RE2& rex) const;
    bool MatchAllLines(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool MatchAllLines(const char* str, rxm::type mod = rxm::ECMAScript) const;

    //   scan is based on regex_search
    bool Scan(const std::regex& rex) const;
    bool Scan(const re2::RE2& rex) const;
    bool Scan(const char pattern, rxm::type mod = rxm::ECMAScript) const;
    bool Scan(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool Scan(const char* str, rxm::type mod = rxm::ECMAScript) const;

    bool ScanLine(const std::regex& rex) const;
    bool ScanLine(const re2::RE2& rex) const;
    bool ScanLine(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool ScanLine(const char* str, rxm::type mod = rxm::ECMAScript) const;

    bool ScanAllLines(const std::regex& rex) const;
    bool ScanAllLines(const re2::RE2& rex) const;
    bool ScanAllLines(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    bool ScanAllLines(const char* str, rxm::type mod = rxm::ECMAScript) const;

    bool ScanList(const xvector<std::regex>& rex_lst) const;
    bool ScanList(const xvector<re2::RE2>& rex_lst) const;
    bool ScanList(const xvector<xstring>& lst, rxm::type mod = rxm::ECMAScript) const;

    bool ScanList(const xvector<std::regex*>& rex_lst) const;
    bool ScanList(const xvector<re2::RE2*>& rex_lst) const;
    bool ScanList(const xvector<xstring*>& lst, rxm::type mod = rxm::ECMAScript) const;

    // exact match (no regex)
    bool Is(const xstring& other) const;
    size_t hash() const;

    // =================================================================================================================================

    int HasNonAscii(int front_skip = 0, int end_skip = 0, int threshold = 0) const;
    bool HasNulls() const;
    bool HasDualNulls() const;
    void RemoveNulls();
    xstring RemoveNonAscii() const;

    // =================================================================================================================================

    xvector<xstring> Findall(const std::regex& rex) const;
    xvector<xstring> Findall(const re2::RE2& rex) const;
    xvector<xstring> Findall(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    xvector<xstring> Findall(const char* pattern, rxm::type mod = rxm::ECMAScript) const;

    xvector<xstring> Findwalk(const std::regex& rex) const;
    xvector<xstring> Findwalk(const re2::RE2& rex) const;
    xvector<xstring> Findwalk(const xstring& pattern, rxm::type mod = rxm::ECMAScript) const;
    xvector<xstring> Findwalk(const char* pattern, rxm::type mod = rxm::ECMAScript) const;

    xvector<xstring> Search(const std::regex& rex, int count = -1) const;
    //xvector<xstring> Search(const re2::RE2& rex, int count = -1) const;
    xvector<xstring> Search(const xstring& pattern, rxm::type mod = rxm::ECMAScript, int count = -1) const;
    xvector<xstring> Search(const char* pattern, rxm::type mod = rxm::ECMAScript, int count = -1) const;

    // =================================================================================================================================

    bool Has(const char var_char) const;
    bool Lacks(const char var_char) const;
    size_t Count(const char var_char) const;
    size_t Count(const xstring& pattern) const;

    // =================================================================================================================================

    xstring Sub(const std::regex& rex, const std::string& replacement) const;
    xstring Sub(const RE2& rex, const std::string& replacement) const;
    xstring Sub(const RE2& rex, const re2::StringPiece& replacement) const;
    xstring Sub(const RE2& rex, const char* replacement) const;
    xstring Sub(const std::string& pattern, const std::string& replacement, rxm::type mod = rxm::ECMAScript) const;
    xstring Sub(const char* pattern, const std::string& replacement, rxm::type mod = rxm::ECMAScript) const;
    xstring Sub(const char* pattern, const char* replacement, rxm::type mod = rxm::ECMAScript) const;

    xstring& Trim();
    xstring& LeftTrim();
    xstring& RightTrim();
    xstring& Trim(const xstring& trim);
    xstring& LeftTrim(const xstring& trim);
    xstring& RightTrim(const xstring& trim);

    // =================================================================================================================================

    xstring operator()(long double x = 0, long double y = 0, long double z = 0, const char removal_method = 's') const;

    // =================================================================================================================================

    int         ToInt() const;
    long        ToLong() const;
    long long   ToLongLong() const;
    size_t      To64() const;
    double      ToDouble() const;
    float       ToFloat() const;

    // =================================================================================================================================

    xstring ToBlack() const;
    xstring ToRed() const;
    xstring ToGreen() const;
    xstring ToYellow() const;
    xstring ToBlue() const;
    xstring ToMegenta() const;
    xstring ToCyan() const;
    xstring ToGrey() const;
    xstring ToWhite() const;

    xstring ToOnBlack() const;
    xstring ToOnRed() const;
    xstring ToOnGreen() const;
    xstring ToOnYellow() const;
    xstring ToOnBlue() const;
    xstring ToOnMegenta() const;
    xstring ToOnCyan() const;
    xstring ToOnGrey() const;
    xstring ToOnWhite() const;

    xstring ResetColor() const;
    xstring ToBold() const;
    xstring ToUnderline() const;
    xstring ToInvertedColor() const;
    // =================================================================================================================================
};

// stand-alone function
template<typename T>
inline typename std::enable_if< std::is_class<T>::value && !std::is_pointer<T>::value, xstring>::type
ToXString(const T& obj)
{
    std::ostringstream ostr;
    ostr << obj;
    return xstring(ostr.str().c_str());
}

template<typename T>
inline typename std::enable_if<!std::is_class<T>::value && !std::is_pointer<T>::value, xstring>::type
ToXString(const T& obj)
{
    std::ostringstream ostr;
    ostr << obj;
    return xstring(ostr.str().c_str());
}


template<typename T>
inline typename std::enable_if< std::is_class<T>::value && std::is_pointer<T>::value, xstring>::type
ToXString(const T& obj)
{
    std::ostringstream ostr;
    ostr << obj;
    return xstring(ostr.str().c_str());
}

template<typename T>
inline typename std::enable_if<!std::is_class<T>::value && std::is_pointer<T>::value, xstring>::type
ToXString(const T& obj)
{
    std::ostringstream ostr;
    ostr << obj;
    return xstring(ostr.str().c_str());
}

// wide string to xstring
xstring WTXS(const wchar_t* wstr);


#include "std_xstring.h"
