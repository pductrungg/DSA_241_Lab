void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
        if (this->terms->empty()) {
        this->terms->add(term);
        return;
    }

    SLinkedList<Term>::Iterator it;
    int pos = 0;
    for (it = this->terms->begin(); it != this->terms->end(); ++it) {
        if ((*it).exp == term.exp) {
            (*it).coeff += term.coeff;

            // remove 0 coeff term
            if ((*it).coeff == 0.0) {
                this->terms->removeAt(pos);
            }
            return;
        }

        if ((*it).exp < term.exp) {
            this->terms->add(pos, term);
            return;
        }

        pos++;
    }
    this->terms->add(term);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
        if (coeff != 0.0) {
        Term newTerm(coeff, exp);
        insertTerm(newTerm);
    }

}

