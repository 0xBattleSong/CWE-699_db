#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include "parse.h"

void traverse(xmlNodePtr *);
int parseDoc(char *);
xmlNodePtr recurseNode(&cur);

uint8_t flag = 255;

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

void traverse(xmlNodePtr *curp) {
	xmlNodePtr cur = *curp;
	while (cur != NULL) {
		printf("%s\n", cur->name);
		cur = cur->next;
	}
	recurseNode(&cur);
}

xmlNodePtr recurseNode(xmlNodePtr *curp) {
	xmlNodePtr cur = *curp;
	return cur;
}

int main(int argc, char *argv[]) 
{
	flag = parseDoc("comVulns.xml");
    return 0;
}
