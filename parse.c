#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "parse.h" // libxml headers included

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

xmlNodePtr traverse(xmlNodePtr *curp) {
	xmlNodePtr cur = *curp;

	while (cur->next != NULL) {
		printf("%s\n", cur->name);
		cur = cur->next;
	}

	if (cur->children != NULL) {
		printf("%s\n", (char *)cur->name);
		return traverse( &(cur->children));
	}
	printf("%s\n", (char *)cur->name);
	return cur;
}

int main(int argc, char *argv[]) 
{
	flag = parseDoc("comVulns.xml");
    return 0;
}
