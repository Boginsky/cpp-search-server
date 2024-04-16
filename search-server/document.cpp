#include "document.h"

#include <iostream>
#include <string>

using namespace std::string_literals;

Document::Document() : id(0), relevance(0.0), rating(0) {}
Document::Document(int id, double relevance, int rating) : id(id), relevance(relevance), rating(rating) {}

std::ostream& operator<<(std::ostream& os, const Document& document) {
    using namespace std::string_literals;

    os << "{ "s
       << "document_id = "s << document.id << ", "s
       << "relevance = "s << document.relevance << ", "s
       << "rating = "s << document.rating << " }"s;

    return os;
}

void PrintDocument(const Document& document) {
    std::cout << "{ "s
         << "document_id = "s << document.id << ", "s
         << "relevance = "s << document.relevance << ", "s
         << "rating = "s << document.rating << " }"s << std::endl;
}

void PrintMatchDocumentResult(int document_id, const std::vector<std::string_view>& words, DocumentStatus status) {
    std::cout << "{ "s
         << "document_id = "s << document_id << ", "s
         << "status = "s << static_cast<int>(status) << ", "s
         << "words ="s;
    for (const std::string_view& word : words) {
        std::cout << ' ' << word;
    }
    std::cout << "}"s << std::endl;
}