/*
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cutils/properties.h>
#include <string.h>
#include <stdio.h>
#include "property_ops.h"

int property_get(const char *key, char *value, const char *default_value) {
    int rc = 0;

    rc =  get_property_value(key,value);
    if( rc > 0) {
      return rc;
    }
    if (NULL != default_value) {
        rc = sprintf(value, "%.*s", PROPERTY_VALUE_MAX - 1, default_value);
    }

    return rc;
}

int property_set(const char *key, const char *value)
{

    set_property_value(key,value);
    return 0;
}

int8_t property_get_bool(const char *key, int8_t default_value) {

    if (!key) {
        return default_value;
    }

    int8_t result = default_value;
    char buf[PROPERTY_VALUE_MAX] = {'\0',};

    int len = property_get(key, buf, "");
    if (len == 1) {
        char ch = buf[0];
        if (ch == '0' || ch == 'n') {
            result = false;
        } else if (ch == '1' || ch == 'y') {
            result = true;
        }
    } else if (len > 1) {
         if (!strcmp(buf, "no") || !strcmp(buf, "false") || !strcmp(buf, "off")) {
            result = false;
        } else if (!strcmp(buf, "yes") || !strcmp(buf, "true") || !strcmp(buf, "on")) {
            result = true;
        }
    }

    return result;

}

#if 0
int64_t property_get_int64(const char *key, int64_t default_value);
int32_t property_get_int32(const char *key, int32_t default_value);
#endif
