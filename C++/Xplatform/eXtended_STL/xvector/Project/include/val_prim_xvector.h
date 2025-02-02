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
#include "base_val_xvector.h"
#include <type_traits>

template<typename T> class val_xvector;
template<typename T, typename enabler_t> class xvector;

template<typename T>
class xvector<T, typename std::enable_if_t<!std::is_class<T>::value && !std::is_pointer<T>::value>> : public val_xvector<T>
{
private:
    typedef typename std::remove_const<T>::type E;// E for Erratic

public:
    using val_xvector<T>::val_xvector;
    using val_xvector<T>::operator=;

    typedef T value_type;
    inline xvector(std::initializer_list<T> lst) : val_xvector<T>(std::move(lst)) { };
    inline xvector(const std::vector<T>& vec) : val_xvector<T>(vec) { };
    inline xvector(std::vector<T>&& vec) noexcept : val_xvector<T>(std::move(vec)) { };
    inline xvector(const xvector<T>& vec) : val_xvector<T>(vec) { };
    inline xvector(xvector<T>&& vec) noexcept : val_xvector<T>(std::move(vec)) { };

    inline void operator=(const xvector<T>& vec) { val_xvector<T>::operator=(vec); };
    inline void operator=(const std::vector<T>& vec) { val_xvector<T>::operator=(vec); };

    inline void operator=(xvector<T>&& vec) { val_xvector<T>::operator=(std::move(vec)); };
    inline void operator=(std::vector<T>&& vec) { val_xvector<T>::operator=(std::move(vec)); };

    inline T GetCommonItems(char const* item);
    template<typename S = std::string>
    inline S Join(const S& str = "") const;
    inline std::string Join(const char str) const;
    inline std::string Join(const char* str) const;
};


template<typename T>
inline T xvector<T, typename std::enable_if_t<!std::is_class<T>::value && !std::is_pointer<T>::value>>::GetCommonItems(char const* item)
{
    size_t size = strlen(item);
    xvector<T> c_vec(size);

    for (int i = 0; i < size; i++)
        c_vec << item[i];

    return this->GetCommonItems(c_vec);
}

template<typename T>
template<typename S>
inline S xvector<T, typename std::enable_if_t<!std::is_class<T>::value && !std::is_pointer<T>::value>>::Join(const S& str) const
{
    std::ostringstream ostr;
    for (const auto& i : *this) {
        ostr << i;
        ostr << str;
    }
    return S(ostr.str().substr(0, ostr.str().size() - str.size()));
}

template<typename T>
inline std::string xvector<T, typename std::enable_if_t<!std::is_class<T>::value && !std::is_pointer<T>::value>>::Join(const char str) const
{
    std::string val;
    val.insert(val.begin(), str);
    return this->Join(val);
}

template<typename T>
inline std::string xvector<T, typename std::enable_if_t<!std::is_class<T>::value && !std::is_pointer<T>::value>>::Join(const char* str) const
{
    return this->Join(std::string(str));
}

