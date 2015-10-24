/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"),
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/


#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dlog.h>

#include <system_info_intf.h>

#ifndef API
#define API __attribute__ ((visibility("default")))
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "CAPI_SYSTEM_INFO"

#define ARRAY_SIZE(name) (sizeof(name)/sizeof(name[0]))

static int get_region_kind(char *buf, unsigned int len)
{
	snprintf(buf, len, "USA");
	return 0;
}

static int get_local_set(char *buf, unsigned int len)
{
	snprintf(buf, len, "us");
	return 0;
}

static int get_panel_resolution_width(char *buf, unsigned int len)
{
	snprintf(buf, len, "1920");
	return 0;
}
static int get_panel_resolution_height(char *buf, unsigned int len)
{
	snprintf(buf, len, "1080");
	return 0;
}
static int get_tv_year(char *buf, unsigned int len)
{
	snprintf(buf, len, "2015");
	return 0;
}
static int get_ttv_supported(char *buf, unsigned int len)
{
	snprintf(buf, len, "true");
	return 0;
}
static int get_tv_chip_type(char *buf, unsigned int len)
{
	snprintf(buf, len, "HAWKP UHD 2015");
	return 0;
}

static const struct external_system_info_key {
	const char *key;
	const char *tag;
	const char *type;
	int (*get_value)(char *buf, unsigned int len);
} system_info_key[] = {
	{ "http://developer.samsung.com/tizen/system/region_kind"	, TAG_CUSTOM, TYPE_STR, get_region_kind	},
	{ "http://developer.samsung.com/tizen/system/local_set"		, TAG_CUSTOM, TYPE_STR, get_local_set },
	{ "http://developer.samsung.com/tizen/system/panel_resolution_width"	, TAG_CUSTOM, TYPE_INT, get_panel_resolution_width },
	{ "http://developer.samsung.com/tizen/system/panel_resolution_height"	, TAG_CUSTOM, TYPE_INT, get_panel_resolution_height },
	{ "http://developer.samsung.com/tizen/system/tv_year"		, TAG_CUSTOM, TYPE_INT, get_tv_year },
	{ "http://developer.samsung.com/tizen/system/ttv_supported"	, TAG_CUSTOM, TYPE_BOOL, get_ttv_supported },
	{ "http://developer.samsung.com/tizen/system/tv_chip_type"	, TAG_CUSTOM, TYPE_STR, get_tv_chip_type },
};

static int get_value_external(const char *tag,
		const char *key, const char *type,
		char *buf, unsigned int len)
{
	int i;
	int key_len, tag_len, type_len;

	if (!tag || !key || !type || !buf)
		return -EINVAL;

	key_len = strlen(key);
	tag_len = strlen(tag);
	type_len = strlen(type);
	if (key_len == 0 || tag_len == 0 || type_len == 0)
		return -EINVAL;

	for (i = 0 ; i < ARRAY_SIZE(system_info_key) ; i++) {
		if (strncmp(system_info_key[i].type, type, type_len))
			continue;
		if (strncmp(system_info_key[i].tag, tag, tag_len))
			continue;
		if (strncmp(system_info_key[i].key, key, key_len))
			continue;

		if (system_info_key[i].get_value)
			return system_info_key[i].get_value(buf, len);
	}

	LOGE("Failed to find system info key in the plugin (%s)", key);
	return -EINVAL;
}

const system_info_external_plugin_interface external_plugin = {
	.get_value_external = get_value_external,
};

API const system_info_external_plugin_interface *system_info_get_external_plugin_interface(void)
{
	return &external_plugin;
}
