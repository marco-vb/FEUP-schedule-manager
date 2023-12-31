#ifndef TYPES_H
#define TYPES_H

#include <bits/stdc++.h>
#include "Student.h"
#include "Course.h"
#include "Class.h"

using namespace std;

//comparing structs

//order students by number
/// Compara dois estudantes por ordem crescente de numero de estudante
struct studentCompare {
    /**
     * @brief Função que compara dois estudantes por ordem crescente de numero de estudante
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeira estudante a comparar
     * @param b Segunda estudante a comparar
     * @return true se o numero de estudante do primeiro estudante for menor que o do segundo
     */
    bool operator()(const Student* a, const Student* b) const {
        return a->getNumber() < b->getNumber();
    }
};

//order courses by code
///struct classCourse que guarda um par de apontadores para uma classe e um curso e o respetivo número de estudantes
struct classCourse {
    string class_;
    string course;
    int students;
    /**
     * @brief Função que compara dois classCourse por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro classCourse a comparar
     * @param b Segundo classCourse a comparar
     * @return true se o codigo da UC do primeiro for menor que o do segundo, ou se os codigos da UC forem iguais e o codigo da turma do primeiro for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const classCourse& a, const classCourse& b) const {
        return (a.course < b.course) ||
               (a.course == b.course && a.class_ < b.class_);
    }

    bool operator<(const classCourse& b) const {
        return (course < b.course) ||
               (course == b.course && class_ < b.class_);
    }
};

/// Compara dois slots por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
struct slotCompare{
    /**
     * @brief Função que compara dois slots por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se o codigo da turma do primeiro slot for menor que o do segundo, ou se os codigos da turma forem iguais e o codigo da unidade curricular do primeiro slot for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const Slot* a, const Slot* b) const {
        return a->getClassCode() < b->getClassCode() ||
               (a->getClassCode() == b->getClassCode() && a->getCourseCode() < b->getCourseCode());
    }
};

/// Compara dois slots por ordem alfabética de codigo da unidade curricular, e em caso de empate por ordem alfabética de codigo da tuma
struct slotCompareByCourse{
    /**
     * @brief Função que compara dois slots por ordem alfabética de codigo da unidade curricular, e em caso de empate por ordem alfabética de codigo da tuma
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se o codigo da unidade curricular do primeiro slot for menor que o do segundo, ou se os codigos da unidade curricular forem iguais e o codigo da turma do primeiro slot for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const Slot a, const Slot b) const {
        return a.getCourseCode() < b.getCourseCode() ||
               (a.getCourseCode() == b.getCourseCode() && a.getClassCode() < b.getClassCode());
    }
};

/// Compara dois slots pela hora de inicio
struct slotCompareByStartHour{
    /**
     * @brief Função que compara dois slots pela hora de inicio, em caso de empate pelo dia da semana
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se a hora de inicio do primeiro slot for menor que a do segundo, ou se as horas de inicio forem iguais e o dia da semana do primeiro slot for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const Slot a, const Slot b) const {
        return a.getStartHour() < b.getStartHour() ||
               (a.getStartHour() == b.getStartHour() && weekDayToNum(a.getDay()) < weekDayToNum(b.getDay()));
    }
};

/// Compara dois slots pela hora de fim
struct slotCompareByEndHour{
    /**
     * @brief Função que compara dois slots pela hora de fim, em caso de empate pelo dia da semana
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se a hora de fim do primeiro slot for menor que a do segundo, ou se as horas de fim forem iguais e o dia da semana do primeiro slot for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const Slot a, const Slot b) const {
        return a.getEndHour() < b.getEndHour() ||
               (a.getEndHour() == b.getEndHour() && weekDayToNum(a.getDay()) < weekDayToNum(b.getDay()));
    }
};

/// Compara dois slots pela dia da semana
struct slotCompareByDay{
    /**
     * @brief Função que compara dois slots pelo dia da semana, em caso de empate pela hora de inicio
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se o dia da semana do primeiro slot for menor que o do segundo, ou se os dias da semana forem iguais e a hora de inicio do primeiro slot for menor que a do segundo, e falso caso contrario
     */
    bool operator()(const Slot a, const Slot b) const {
        return weekDayToNum(a.getDay()) < weekDayToNum(b.getDay()) ||
               (weekDayToNum(a.getDay()) == weekDayToNum(b.getDay()) && a.getStartHour() < b.getStartHour());
    }
};


//define sets
/// Renomeia o tipo <Student*, studentCompare> para studentSet, para melhor legibilidade
typedef set<Student*, studentCompare> studentSet;
/// Renomeia o tipo set<classCourse*> para classCourseSet, para melhor legibilidade
typedef set<classCourse*> classCoursesSet;
/// Renomeia o tipo set<Slot*, slotCompare> para slotSet, para melhor legibilidade
typedef multiset<Slot*, slotCompare> slotSet;

#endif
