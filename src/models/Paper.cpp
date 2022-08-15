/**
 * @project Automatic Examination
 * @file Paper.cpp
 * @location src/models
 * @brief Model for a full paper
 * @date 2022/8/12
 */

#include "Paper.h"

//namespace nlohmann
//{
//    template<>
//    struct adl_serializer<std::shared_ptr<BaseProblem>>
//    {
//        static void to_json(json& j, const std::shared_ptr<BaseProblem>& opt)
//        {
//            if (opt)
//            {
//                switch (opt->getProblemType())
//                {
//                    case SingleChoice:
//                        j = *(std::static_pointer_cast<SingleChoiceProblem>(opt));
//                        break;
//                    case MultipleChoice:
//                        j = *(std::static_pointer_cast<MultipleChoiceProblem>(opt));
//                        break;
//                    case TrueOrFalse:
//                        j = *(std::static_pointer_cast<TrueOrFalseProblem>(opt));
//                        break;
//                    case ShortAnswer:
//                        j = *(std::static_pointer_cast<ShortAnswerProblem>(opt));
//                        break;
//                    default:
//                        j = *opt;
//                        break;
//                }
//            }
//            else
//            {
//                j = nullptr;
//            }
//        }
//
//        static void from_json(const json& j, std::shared_ptr<BaseProblem>& opt)
//        {
//            if (j.is_null())
//            {
//                opt = nullptr;
//            }
//            else
//            {
//                switch (j.at("problemType").get<ProblemType>())
//                {
//                    case SingleChoice:
//                        opt = std::make_shared<SingleChoiceProblem>(j.get<SingleChoiceProblem>());
//                        break;
//                    case MultipleChoice:
//                        opt = std::make_shared<MultipleChoiceProblem>(j.get<MultipleChoiceProblem>());
//                        break;
//                    case TrueOrFalse:
//                        opt = std::make_shared<TrueOrFalseProblem>(j.get<TrueOrFalseProblem>());
//                        break;
//                    case ShortAnswer:
//                        opt = std::make_shared<ShortAnswerProblem>(j.get<ShortAnswerProblem>());
//                        break;
//                    default:
//                        opt = std::make_shared<BaseProblem>(j.get<BaseProblem>());
//                        break;
//                }
//            }
//        }
//    };
//}

void Paper::mock() {
    for (int i = 0; i < 4; i++) {
        problems.push_back(std::make_shared<SingleChoiceProblem>());
        problems.push_back(std::make_shared<MultipleChoiceProblem>());
        problems.push_back(std::make_shared<TrueOrFalseProblem>());
        problems.push_back(std::make_shared<ShortAnswerProblem>());
    }
}

json Paper::toJson() const {
    auto j = json();
    for (auto i : problems) {
        j.push_back(i->toJson());
    }
    return j;
}

Paper Paper::fromJson(const json j) {
    Paper p;
    for (auto i : j) {
        p.problems.push_back(problemFromJson(i));
    }
    return p;
}

const std::vector<std::shared_ptr<BaseProblem>> &Paper::getProblems() const {
    return problems;
}

void Paper::setProblems(const std::vector<std::shared_ptr<BaseProblem>> &problems) {
    Paper::problems = problems;
}

std::shared_ptr<BaseProblem> problemFromJson(const json j) {
    switch (j.at("problemType").get<ProblemType>())
    {
        case SingleChoice:
            return std::make_shared<SingleChoiceProblem>(j);
        case MultipleChoice:
            return std::make_shared<MultipleChoiceProblem>(j);
            break;
        case TrueOrFalse:
            return std::make_shared<TrueOrFalseProblem>(j);
            break;
        case ShortAnswer:
            return std::make_shared<ShortAnswerProblem>(j);
            break;
        default:
            return std::make_shared<BaseProblem>(j);
            break;
    }
}
