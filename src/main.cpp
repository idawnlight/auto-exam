/**
 * @project Automatic Examination
 * @file main.cpp
 * @location src
 * @brief Main function
 * @date 2022/8/12
 */

#include "ui/window/EntryWidget.h"
#include "ui/window/EditWindow.h"
#include "ui/window/ExamWindow.h"

#include "models/Paper.h"

#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    Paper test;
    test.mock();
    json j = test.toJson();
    std::cout << j << std::endl;
    auto test2 = Paper::fromJson(j);
//    auto test2 = j.get<Paper>();
    auto test3 = std::make_shared<Paper>(test2);

    for (const auto& i : test3->getProblems()) {
        switch (i->getProblemType()) {
            case SingleChoice:
                {
                    auto tmp = std::static_pointer_cast<SingleChoiceProblem>(i);
                    std::cout << "SingleChoice" << std::endl;
                }
                break;
            case MultipleChoice:
                {
                    auto tmp = std::static_pointer_cast<MultipleChoiceProblem>(i);
                    std::cout << "MultipleChoice" << std::endl;
                }
                break;
            case TrueOrFalse:
                {
                    auto tmp = std::static_pointer_cast<TrueOrFalseProblem>(i);
                    std::cout << "TrueOrFalse" << std::endl;
                }
                break;
            case ShortAnswer:
                {
                    auto tmp = std::static_pointer_cast<ShortAnswerProblem>(i);
                    std::cout << "ShortAnswer" << std::endl;
                }
                break;
            default:
                std::cout << "Default" << std::endl;
                break;
        }
    }

//    std::vector<std::shared_ptr<BaseProblem>> v;
//    auto tmp = std::make_shared<SingleChoiceProblem>();
//    std::cout << tmp->toJson() << std::endl;
//    v.push_back(std::move(tmp));
//    std::cout << v[0]->toJson() << std::endl;

    QApplication a(argc, argv);
    EntryWidget entry;
    EditWindow setup;

    QObject::connect(&entry, &EntryWidget::editPaper, &setup, &EditWindow::show);

    entry.show();
    return a.exec();
}
