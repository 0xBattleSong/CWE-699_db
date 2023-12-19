#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>

xmlNodePtr *traverse(xmlNodePtr *);

xmlNodePtr cur;
xmlDocPtr doc;
xmlChar *rootName = (xmlChar *)"\0";

int parseDoc(char *filePath) {
	doc = xmlParseFile(filePath);
	if (doc == NULL) {
		fprintf(stderr, "Document not parsed successfully.\n");
		return 1;
	}
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr, "Empty document.\n");
		return 2;
	}

	rootName = (xmlChar *)cur->name;

	traverse(&cur);
	return 0;

}

xmlNodePtr *traverse(xmlNodePtr *curp) {
	cur = *curp;

	if (cur->type == XML_TEXT_NODE) {
		cur = cur->next;
	}
	if (cur->type != XML_TEXT_NODE) {
		printf("%s\n", cur->name);
	}

	if (cur->children->next != NULL) {
		cur = *traverse( &(cur->children));
	} else if (cur->parent->next != NULL) {
		cur = *traverse( &(cur->parent->next));
	}

	return &cur;

}

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	parseDoc(argv[1]);

    return 0;
}
