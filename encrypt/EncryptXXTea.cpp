//
//  EncryptXXTea.cpp
//  feiio_libs
//
//  Created by Yuanfei He on 15-3-19.
//  Copyright (c) 2015年 Yuanfei He. All rights reserved.
//

#include "EncryptXXTea.h"
#include "xxtea/xxtea.h"
#include <cstring>

struct UserData
{
    int level;
    int num;
    int t;
};

unsigned char *EncryptXXTea::decode()
{
    UserData user_d = {10,20,30};
    unsigned char *t_data = (unsigned char *)&user_d;
    const  char *key_s = "YuanfeiTestXXTea";
    xxtea_long key_len = strlen(key_s);
    xxtea_long ret_len;
    unsigned char *bufs=xxtea_encrypt(t_data, sizeof(UserData), (unsigned char*)key_s, key_len, &ret_len);
    
    char t_buf[512];
    memset(&t_buf, 0, 512);
    memcpy(&t_buf, bufs, ret_len+1);
    
    key_s = "YuanfeiTestXXTea";
    key_len = strlen(key_s);
    xxtea_long de_len;
    unsigned char *de_data=xxtea_decrypt(bufs, ret_len, (unsigned char*)key_s, key_len, &de_len);
    memset(&t_buf, 0, 512);
    memcpy(&t_buf, de_data, ret_len+1);
    
    UserData decod;
    memset(&decod, 0, sizeof(UserData));
    memcpy(&decod, de_data, sizeof(UserData));
    return nullptr;

}

unsigned char *EncryptXXTea::encode()
{
    return  nullptr;
}