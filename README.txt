

&&  FlightController &&
Det er hovedsakelig to mulige tilnærminger til FCs(FlightController) stabilisasjonssystem, grad-basert og aksererasjonsbasert.
    Systemet baserer seg på en PID algoritme, denne tar en ønsket verdi(setpoint) og en målt verdi(value). Disse to verdiene kommer fra ulike kilder, setpoint kommer fra fjernkontrollen og value fra gyroskop/akselerometer. Essensen i diskusjonen om hva systemet skal basere seg på, grader eller akseleratsjon, kommer fra dette: når bruker setter stikka frem, la oss si pitch, betyr det at quadcopteret skal akselerere med en viss akselerasjon, eller at quadcopteret skal tippe fremover/bakover med et visst antall grader?
    Det er fordeler og ulemper ved begge metodene:
    Aks
	Pro
	 -Quadcopteret vil trolig stå mer stabilt når det står stille, siden det kan akkselerere uten at det heller
	Con
	 -Det kan virke forvirrende og lite naturlig at stikka kontrollerer akselerasjon, ikke hastighet. Dette vil si at om man heller stikka aldri så lite fremover så vil quadcopteret forsøke å holde en viss akselerasjon, dermed øke hastigheten mer og mer.
    Grader
	Pro
	 -Mer naturlig enn akselerasjon, da grader er veldig tett knyttet opp med hastighet
	Con
	 -Muligens mindre stabilt

    En mulighet er å legge til rette for begge systemene, og ha en bryter på fjernkontroll som bytter mellom de to.
