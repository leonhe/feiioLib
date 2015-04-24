//
// Created by Yuanfei He on 15/4/8.
//

#include "utils/StringUtils.h"
#include "cocos2d.h"
#include <string>


USING_NS_CC;
using  namespace std;

namespace  feiio
{

    ValueVector &StringUtils::split(const std::string &src_str,
            const std::string &flag,
            ValueVector &con) {

        std::size_t found_it=0;
        std::size_t index = 0;
        do{
            found_it = src_str.find_first_of(",",index);
            auto str=src_str.substr(index,found_it);

            con.push_back(Value(str));

            if(found_it!=string::npos)
            {
                index = found_it+1;
            }
        }while(found_it!=string::npos);

        return con;
    }
}