/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file AstAnalysis.h
 *
 * Defines the interface for AST analysis passes.
 *
 ***********************************************************************/
#pragma once

#include <iostream>

namespace souffle {

class AstTranslationUnit;

class AstAnalysis {
public:
    virtual ~AstAnalysis() = default;

    virtual void run(const AstTranslationUnit& translationUnit) = 0;

    virtual void print(std::ostream& os) const {}

    /** Add support for printing nodes */
    friend std::ostream& operator<<(std::ostream& out, const AstAnalysis& other) {
        other.print(out);
        return out;
    }
};

}  // end of namespace souffle
