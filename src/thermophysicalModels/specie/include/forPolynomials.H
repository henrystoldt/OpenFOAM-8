/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#ifndef forPolynomials_H
#define forPolynomials_H

#include "specie.H"

#include "icoPolynomial.H"

#include "hPolynomialThermo.H"

#include "sensibleEnthalpy.H"
#include "sensibleInternalEnergy.H"

#include "logPolynomialTransport.H"
#include "polynomialTransport.H"

#include "thermo.H"

#include "forThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define forPolynomialEquations(Mu, He, Cp, Args...)                            \
    forThermo(Mu, He, Cp, icoPolynomial, specie, Args);

#define forPolynomialEnergiesAndThermos(Mu, Args...)                           \
    forPolynomialEquations(Mu, sensibleEnthalpy, hPolynomialThermo, Args);     \
    forPolynomialEquations(Mu, sensibleInternalEnergy, hPolynomialThermo, Args)

#define forPolynomialTransports(Args...)                                       \
    forPolynomialEnergiesAndThermos(logPolynomialTransport, Args);             \
    forPolynomialEnergiesAndThermos(polynomialTransport, Args)

#define forPolynomials(Macro, Args...)                                         \
    forPolynomialTransports(Macro, Args)

#endif

// ************************************************************************* //
