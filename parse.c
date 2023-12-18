#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "parse.h" // libxml headers included

uint8_t flag = 255;

struct nodeDocSet {
	xmlDocPtr doc;
	xmlNodePtr cur;
};
struct nodeDocSet set;

struct nodeDocSet *loadDoc(char *docPath) {
	set.doc = xmlParseFile(docPath);
	if (set.doc == NULL) {
		fprintf(stderr, "Document not parsed successfully.\n");
		return NULL;
	}
	set.cur = xmlDocGetRootElement(set.doc);
	if (set.cur == NULL) {
		fprintf(stderr, "empty document\n");
		xmlFreeDoc(set.doc);
	}
	return &set;
}

int parseDoc(char *docPath) {
	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docPath);
	if (doc == NULL) {
		fprintf(stderr, "Document not parsed successfully.\n");
		return 1;
	}
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr, "empty document\n");
		xmlFreeDoc(doc);
		return 2;
	}

	traverse(&cur);

	xmlFreeDoc(doc);

	return 0;
}

xmlNodePtr traverse(xmlNodePtr *curp) {
	xmlNodePtr cur = *curp;

	printf("%s\n", cur->name);
	cur = cur->children->next;

	while (cur->next != NULL) {

		flag = xmlStrcmp(cur->name, (xmlChar *)"text");
		if (flag != 0) {
			printf("%s\n", cur->name);
		}

		if (cur->children != NULL && flag != 0) {
			cur = cur->children;
		}
		else if (cur->next != NULL) {
			cur = cur->next;
		}

	}

	return cur;
}

int main(int argc, char *argv[]) 
{
	flag = parseDoc("comVulns.xml");
    return 0;
}
