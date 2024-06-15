
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Database.h>

#include <iostream>
#pragma link "sqlitecpp.lib" 

int main() {
    try {
        SQLite::Database db("docs.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        //db.exec("CREATE TABLE IF NOT EXISTS Documents (id INTEGER PRIMARY KEY, text TEXT, content BLOB, create_data INTEGER)");

        SQLite::Statement query(db, "INSERT INTO Documents(text, content, create_data) VALUES (?, ?, ?)");
        query.bind(1, "Alice");
        query.bind(2, "");
        query.bind(3, 12315);
        query.exec();

        std::cout << "Данные успешно добавлены в таблицу." << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Ошибка при работе с базой данных: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
