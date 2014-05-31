/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include <dlog.h>

#include <system_info.h>
#include <system_info_private.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "CAPI_SYSTEM_INFO"

int system_info_get_value_from_cpuinfo(char *field, char **value)
{
	int tmpStrlen = 0;
	FILE *cpuinfo = NULL;
	char *name = NULL;
	char str[MAXBUFSIZE] = "";
	char tmpStr[MAXBUFSIZE] = "";

	cpuinfo = fopen(CPU_INFO_FILE_PATH, "r");
	if (NULL == cpuinfo) {
		LOGE("cannot file open %s file!!!", CPU_INFO_FILE_PATH);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	while (fgets(str, MAXBUFSIZE, cpuinfo)) {
		if (!strncmp(field, str, strlen(field))) {
			name = strchr(str, ':');
			tmpStrlen = strlen(name+2);
			strncpy(tmpStr, name+2, tmpStrlen);
			tmpStr[tmpStrlen-1] = '\0';
			*value = strdup(tmpStr);
			if (*value == NULL) {
				LOGE("OUT_OF_MEMORY(0x%08x)", SYSTEM_INFO_ERROR_OUT_OF_MEMORY);
				fclose(cpuinfo);
				return SYSTEM_INFO_ERROR_OUT_OF_MEMORY;
			}
		}
	}

	if (system_info_get_system_info_model_type() == SYSTEM_INFO_MODEL_TYPE_EMULATOR)
		*value = strdup("default");

	if (*value == NULL) {
		LOGE("cannot get %s in cpuinfo", field);
		fclose(cpuinfo);
		return SYSTEM_INFO_ERROR_OUT_OF_MEMORY;
	}

	fclose(cpuinfo);

	return SYSTEM_INFO_ERROR_NONE;
}

int system_info_get_bsp_info(const char *key, char **value)
{
	char *id_field;
	char *string = NULL;
	char *model = NULL;
	char *revision = NULL;
	char Rrevision[MAXBUFSIZE] = "";
	char file_path[MAXBUFSIZE] = "";

	if (system_info_get_system_info_model_type() == SYSTEM_INFO_MODEL_TYPE_EMULATOR) {
		LOGE("cannot get Hardware info in emulator!!!");
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	if (system_info_get_value_from_cpuinfo("Hardware", &model)) {
		LOGE("cannot get Hardware info from cpuinfo file!!!");
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	if (system_info_get_value_from_cpuinfo("Revision", &revision)) {
		LOGE("cannot get Hardware info from cpuinfo file!!!");
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	if (!revision || !strcmp(revision, "default")) {
		LOGE("cannot get revision info from cpuinfo file!!!");
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	snprintf(Rrevision, MAXBUFSIZE, "R%s", revision);
	snprintf(file_path, MAXBUFSIZE, "/etc/config/board-config-%s.xml", model);

	if (access(file_path, R_OK)) {
		LOGE("cannot find file %s!!!", file_path);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	id_field = strdup(key);

	if (system_info_get_value_from_xml(file_path, Rrevision, id_field, &string)) {
		free(id_field);
		free(model);
		free(revision);
		LOGE("cannot get aud_amrwb info from %s!!!", file_path);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	free(id_field);
	free(model);
	free(revision);

	*value = string;

	return SYSTEM_INFO_ERROR_NONE;
}
