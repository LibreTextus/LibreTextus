#include "grammar.hpp"

Libre::Grammar::Grammar() : grammar_map{
		{"a-apf", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
						}},
		{"a-apf-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-apm", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"a-apm-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-apn", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"a-apn-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"a-asf", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"a-asf-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-asf-s", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Superlative"
								}},
		{"a-asm", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"a-asm-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-asn", {
								"Part of Speech: Adjective",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"a-asn-c", {
									"Part of Speech: Adjective",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"a-dpf", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"a-dpm", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"a-dpm-c", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Plural",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-dpn", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"a-dsf", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"a-dsf-c", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-dsf-s", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Superlative"
								}},
		{"a-dsm", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"a-dsm-c", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Singular",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-dsm-s", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Singular",
									"Gender: Masculine",
									"Degree: Superlative"
								}},
		{"a-dsn", {
								"Part of Speech: Adjective",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"a-dsn-c", {
									"Part of Speech: Adjective",
									"Case: Dative",
									"Number: Singular",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"adv", {
							"Adverb or adverb and particle combined"
						}},
		{"adv-c", {
								"Part of Speech: Case: Accusative",
								"Contracted form"
							}},
		{"adv-i", {
								"Part of Speech: Case: Accusative",
								"Interrogative - vragend woord"
							}},
		{"adv-s", {
								"Part of Speech: Case: Accusative",
								"Degree: Superlative"
							}},
		{"a-gms", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Gender: Masculine",
								"Degree: Superlative"
							}},
		{"a-gpf", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"a-gpm", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"a-gpm-c", {
									"Part of Speech: Adjective",
									"Case: Genitive",
									"Number: Plural",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-gpn", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"a-gpn-c", {
									"Part of Speech: Adjective",
									"Case: Genitive",
									"Number: Plural",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"a-gsf", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"a-gsf-c", {
									"Part of Speech: Adjective",
									"Case: Genitive",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-gsm", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"a-gsm-c", {
									"Part of Speech: Adjective",
									"Case: Genitive",
									"Number: Singular",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-gsn", {
								"Part of Speech: Adjective",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"a-gsn-s", {
									"Part of Speech: Adjective",
									"Case: Genitive",
									"Number: Singular",
									"Gender: Neuter",
									"Degree: Superlative"
								}},
		{"a-npf", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"a-npf-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-npm", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"a-npm-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-npn", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"a-npn-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"a-npn-s", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Neuter",
									"Degree: Superlative"
								}},
		{"a-nsf", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"a-nsf-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Singular",
									"Gender: Feminine",
									"Degree: Comparative"
								}},
		{"a-nsm", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"a-nsm-att", {
										"Part of Speech: Adjective",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine",
										"attic Greek form"
									}},
		{"a-nsm-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Singular",
									"Gender: Masculine",
									"Degree: Comparative"
								}},
		{"a-nsn", {
								"Part of Speech: Adjective",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"a-nsn-c", {
									"Part of Speech: Adjective",
									"Case: Nominative",
									"Number: Singular",
									"Gender: Neuter",
									"Degree: Comparative"
								}},
		{"a-nui", {
								"Indeclinable Numeral"
							}},
		{"a-nui-abb", {
										"Part of Speech: Adjective",
										"Case: Nominative",
										"abbreviated form"
									}},
		{"aram", {
							 "aramaic transliterated word"
						 }},
		{"a-vpm", {
								"Part of Speech: Adjective",
								"Case: Vocative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"a-vsf", {
								"Part of Speech: Adjective",
								"Case: Vocative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"a-vsm", {
								"Part of Speech: Adjective",
								"Case: Vocative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"c-apm", {
								"Part of Speech: Reciprocal pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"c-dpm", {
								"Part of Speech: Reciprocal pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"c-dpn", {
								"Part of Speech: Reciprocal pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"c-gpm", {
								"Part of Speech: Reciprocal pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"c-gpn", {
								"Part of Speech: Reciprocal pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"cond", {
							 "conditional particle or conjunction",
						 }},
		{"cond-c", {
								 "Part of Speech: Contracted form"
							 }},
		{"cond-p", {
								 "Part of Speech: Contracted form"
							 }},
		{"conj", {
							 "conjunction or conjunctive particle"
						 }},
		{"d-apf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"d-apm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"d-apm-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Masculine",
									"Contracted form"
								}},
		{"d-apn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"d-asf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"d-asm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"d-asm-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Masculine",
									"Contracted form"
								}},
		{"d-asn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"d-dpf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"d-dpm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"d-dpm-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Dative",
									"Number: Plural",
									"Gender: Masculine",
									"Contracted form"
								}},
		{"d-dpn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"d-dsf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"d-dsm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"d-dsn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"d-gpf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"d-gpm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"d-gpn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"d-gsf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"d-gsm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"d-gsn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"d-npf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"d-npm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"d-npm-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Masculine",
									"Contracted form"
								}},
		{"d-npn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"d-npn-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Nominative",
									"Number: Plural",
									"Gender: Neuter",
									"Contracted form"
								}},
		{"d-nsf", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"d-nsm", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"d-nsm-c", {
									"Part of Speech: Demonstrative pronoun",
									"Case: Nominative",
									"Number: Singular",
									"Gender: Masculine",
									"Contracted form"
								}},
		{"d-nsn", {
								"Part of Speech: Demonstrative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"f-1asm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-1dsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-1gsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: First",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-2asm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-2asm-c", {
									 "Part of Speech: Reflexive pronoun",
									 "Person: Second",
									 "Case: Accusative",
									 "Number: Singular",
									 "Gender: Masculine",
									 "Contracted form"
								 }},
		{"f-2dsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Second",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-2gsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Second",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-3apf", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"f-3apm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"f-3apn", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"f-3asf", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"f-3asm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-3asn", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"f-3dpf", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"f-3dpm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"f-3dsf", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"f-3dsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-3gpm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Genitive",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"f-3gsf", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"f-3gsm", {
								 "Part of Speech: Reflexive pronoun",
								 "Person: Third",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"f-gpf", {
								"Part of Speech: Reflexive pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"heb", {
							"hebrew transliterated word",
							"Hebreeuws overgezet woord"
						}},
		{"i-apf", {
								"Part of Speech: Interrogative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"i-apm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"i-asf", {
								"Part of Speech: Interrogative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"i-asm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"i-asn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"i-dpm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"i-dsf", {
								"Part of Speech: Interrogative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"i-dsm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"i-dsn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"i-gpm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"i-gpn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"i-gsf", {
								"Part of Speech: Interrogative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"i-gsm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"i-gsn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"inj", {
							"Interjection"
						}},
		{"i-npm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"i-npn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"i-nsf", {
								"Part of Speech: Interrogative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"i-nsm", {
								"Part of Speech: Interrogative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"i-nsn", {
								"Part of Speech: Interrogative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"k-apf", {
								"Part of Speech: Correlative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"k-apm", {
								"Part of Speech: Correlative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"k-apn", {
								"Part of Speech: Correlative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"k-asm", {
								"Part of Speech: Correlative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"k-asn", {
								"Part of Speech: Correlative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"k-dsn", {
								"Part of Speech: Correlative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"k-gpm", {
								"Part of Speech: Correlative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"k-gsn", {
								"Part of Speech: Correlative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"k-npf", {
								"Part of Speech: Correlative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"k-npm", {
								"Part of Speech: Correlative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"k-npn", {
								"Part of Speech: Correlative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"k-nsm", {
								"Part of Speech: Correlative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"k-nsn", {
								"Part of Speech: Correlative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"n-apf", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"n-apf-c", {
									"Part of Speech: Noun",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Feminine",
									"Contracted form"
								}},
		{"n-apm", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"n-apn", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"n-apn-c", {
									"Part of Speech: Noun",
									"Case: Accusative",
									"Number: Plural",
									"Gender: Neuter",
									"Contracted form"
								}},
		{"n-asf", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"n-asf-c", {
									"Part of Speech: Noun",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Feminine",
									"Contracted form"
								}},
		{"n-asm", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"n-asn", {
								"Part of Speech: Noun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"n-dpf", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"n-dpm", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"n-dpn", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"n-dsf", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"n-dsm", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"n-dsn", {
								"Part of Speech: Noun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"n-gmp", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Gender: Masculine",
								"Particle attached"
							}},
		{"n-gpf", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"n-gpm", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"n-gpn", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"n-gsf", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"n-gsm", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"n-gsn", {
								"Part of Speech: Noun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"n-li", {
							 "Indeclinable Letter",
							 "Niet te verbuigen letter"
						 }},
		{"n-nam", {
								"Part of Speech: Noun",
								"Case: Nominative"
							}},
		{"n-npf", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"n-npm", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"n-npn", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"n-nsf", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"n-nsm", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"n-nsn", {
								"Part of Speech: Noun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"n-nsn-c", {
									"Part of Speech: Noun",
									"Case: Nominative",
									"Number: Singular",
									"Gender: Neuter",
									"Contracted form"
								}},
		{"n-oi", {
							 "Indeclinable Noun of Other type"
						 }},
		{"n-pri", {
								"Indeclinable Proper Noun"
							}},
		{"n-vpf", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"n-vpm", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"n-vpn", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"n-vsf", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"n-vsm", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"n-vsn", {
								"Part of Speech: Noun",
								"Case: Vocative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"p-1ap", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Accusative",
								"Number: Plural"
							}},
		{"p-1as", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Accusative",
								"Number: Singular"
							}},
		{"p-1as-c", {
									"Part of Speech: Personal pronoun",
									"Person: First",
									"Case: Accusative",
									"Number: Singular",
									"Contracted form"
								}},
		{"p-1dp", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Dative",
								"Number: Plural"
							}},
		{"p-1ds", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Dative",
								"Number: Singular"
							}},
		{"p-1ds-c", {
									"Part of Speech: Personal pronoun",
									"Person: First",
									"Case: Dative",
									"Number: Singular",
									"Contracted form"
								}},
		{"p-1gp", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Genitive",
								"Number: Plural"
							}},
		{"p-1gs", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Genitive",
								"Number: Singular"
							}},
		{"p-1np", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Nominative",
								"Number: Plural"
							}},
		{"p-1ns", {
								"Part of Speech: Personal pronoun",
								"Person: First",
								"Case: Nominative",
								"Number: Singular"
							}},
		{"p-1ns-c", {
									"Part of Speech: Personal pronoun",
									"Person: First",
									"Case: Nominative",
									"Number: Singular",
									"Contracted form"
								}},
		{"p-2ap", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Accusative",
								"Number: Plural"
							}},
		{"p-2as", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Accusative",
								"Number: Singular"
							}},
		{"p-2dp", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Dative",
								"Number: Plural"
							}},
		{"p-2ds", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Dative",
								"Number: Singular"
							}},
		{"p-2gp", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Genitive",
								"Number: Plural"
							}},
		{"p-2gs", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Genitive",
								"Number: Singular"
							}},
		{"p-2np", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Nominative",
								"Number: Plural"
							}},
		{"p-2ns", {
								"Part of Speech: Personal pronoun",
								"Person: Second",
								"Case: Nominative",
								"Number: Singular"
							}},
		{"p-apf", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"p-apm", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"p-apn", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"p-asf", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"p-asm", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"p-asn", {
								"Part of Speech: Personal pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"p-dpf", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"p-dpm", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"p-dpn", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"p-dsf", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"p-dsm", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"p-dsn", {
								"Part of Speech: Personal pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"p-gpf", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"p-gpm", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"p-gpn", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"p-gsf", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"p-gsm", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"p-gsn", {
								"Part of Speech: Personal pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"p-npm", {
								"Part of Speech: Personal pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"p-npn", {
								"Part of Speech: Personal pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"p-nsf", {
								"Part of Speech: Personal pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"p-nsm", {
								"Part of Speech: Personal pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"p-nsn", {
								"Part of Speech: Personal pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"prep", {
							 "preposition"
						 }},
		{"prt", {
							"Particle, disjunctive particle"
						}},
		{"prt-i", {
								"Part of Speech: Number: Plural",
								"Interrogative - vragend woord"
							}},
		{"prt-n", {
								"Part of Speech: Number: Plural",
								"Negative"
							}},
		{"q-apf", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"q-apm", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"q-apn", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"q-asf", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"q-asn", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"q-dsn", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"q-gpn", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"q-npf", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"q-npm", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"q-nsm", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"q-nsn", {
								"Part of Speech: Correlative or Interrogative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"r-apf", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"r-apm", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"r-apn", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"r-asf", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"r-asm", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"r-asm-p", {
									"Part of Speech: Relative pronoun",
									"Case: Accusative",
									"Number: Singular",
									"Gender: Masculine",
									"Particle attached"
								}},
		{"r-asn", {
								"Part of Speech: Relative pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"r-dpf", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"r-dpm", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"r-dpn", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"r-dsf", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"r-dsm", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"r-dsn", {
								"Part of Speech: Relative pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"r-gpf", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"r-gpm", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"r-gpn", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"r-gsf", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"r-gsm", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"r-gsn", {
								"Part of Speech: Relative pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"r-gsn-att", {
										"Part of Speech: Relative pronoun",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter",
										"attic Greek form"
									}},
		{"r-npf", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"r-npm", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"r-npn", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"r-nsf", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"r-nsm", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"r-nsn", {
								"Part of Speech: Relative pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"s-1apf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-1apm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-1apn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-1asf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-1asm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"s-1asn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"s-1dpf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-1dpm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-1dpn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-1dsf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-1dsm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"s-1dsn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"s-1gpf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Genitive",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-1gpn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Genitive",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-1gsf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-1npf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-1npm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-1npn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-1nsf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-1nsm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"s-1nsn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: First",
								 "Case: Nominative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"s-2apf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-2apm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-2apn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-2asf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-2asn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Accusative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"s-2dpf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-2dpm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Dative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-2dsf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-2dsm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Dative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"s-2gpf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Genitive",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-2gsf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Genitive",
								 "Number: Singular",
								 "Gender: Feminine"
							 }},
		{"s-2npf", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Feminine"
							 }},
		{"s-2npm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Masculine"
							 }},
		{"s-2npn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Nominative",
								 "Number: Plural",
								 "Gender: Neuter"
							 }},
		{"s-2nsm", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Nominative",
								 "Number: Singular",
								 "Gender: Masculine"
							 }},
		{"s-2nsn", {
								 "Part of Speech: Posessive pronoun",
								 "Person: Second",
								 "Case: Nominative",
								 "Number: Singular",
								 "Gender: Neuter"
							 }},
		{"t-apf", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"t-apm", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"t-apn", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"t-asf", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"t-asm", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"t-asn", {
								"Part of Speech: Definite article",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"t-dpf", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"t-dpm", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"t-dpn", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"t-dsf", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"t-dsm", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"t-dsn", {
								"Part of Speech: Definite article",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"t-gpf", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"t-gpm", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"t-gpn", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"t-gsf", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"t-gsm", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"t-gsn", {
								"Part of Speech: Definite article",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"t-npf", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"t-npm", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"t-npn", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"t-nsf", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"t-nsm", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"t-nsn", {
								"Part of Speech: Definite article",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"v-2aai-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2aai-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2aai-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aai-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2aai-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aai-3p-att", {
												"Part of Speech: Verb",
												"Tense: Second Aorist",
												"Voice: Active",
												"Mood: Indicative",
												"Person: Third",
												"Number: Plural",
												"attic form"
											}},
		{"v-2aai-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2aam-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aam-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Imperative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2aam-2s-ap", {
											 "Part of Speech: Verb",
											 "Tense: Second Aorist",
											 "Voice: Active",
											 "Mood: Imperative",
											 "Person: Second",
											 "Number: Singular",
											 "Apocopated form"
										 }},
		{"v-2aam-2s-att", {
												"Part of Speech: Verb",
												"Tense: Second Aorist",
												"Voice: Active",
												"Mood: Imperative",
												"Person: Second",
												"Number: Singular",
												"attic form"
											}},
		{"v-2aam-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Imperative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aam-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Imperative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2aan", {
								 "Part of Speech: Verb",
								 "Tense: Second Aorist",
								 "Voice: Active",
								 "Mood: Infinitive"
							 }},
		{"v-2aao-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Optative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aao-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Optative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2aap-apf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2aap-apm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2aap-asf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2aap-asm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2aap-asn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2aap-dpf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2aap-dpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2aap-dsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2aap-dsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2aap-gpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2aap-gsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2aap-gsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2aap-gsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2aap-npf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2aap-npm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2aap-npn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Neuter"
									 }},
		{"v-2aap-nsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2aap-nsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2aap-nsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2aas-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2aas-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2aas-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aas-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2aas-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aas-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Active",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2adi-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2adi-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2adi-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2adi-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2adi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2adm-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2adm-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Imperative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2adm-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Imperative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2adn", {
								 "Part of Speech: Verb",
								 "Tense: Second Aorist",
								 "Voice: Middle deponent",
								 "Mood: Infinitive"
							 }},
		{"v-2ado-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Optative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2ado-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Optative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2adp-apm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2adp-apn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Neuter"
									 }},
		{"v-2adp-asf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2adp-asm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2adp-asn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2adp-dpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2adp-dpn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Plural",
										 "Gender: Neuter"
									 }},
		{"v-2adp-gpf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2adp-gpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2adp-gpn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Neuter"
									 }},
		{"v-2adp-gsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2adp-gsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2adp-gsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2adp-npf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2adp-npm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2adp-nsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle deponent",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2ads-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2ads-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2ads-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2ads-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2ads-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle deponent",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2ami-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2ami-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2ami-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2ami-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2ami-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2ami-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2amm-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2amm-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Imperative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2amn", {
								 "Part of Speech: Verb",
								 "Tense: Second Aorist",
								 "Voice: Middle",
								 "Mood: Infinitive"
							 }},
		{"v-2amp-gsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2amp-npm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2amp-nsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Middle",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2ams-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2ams-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2ams-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2ams-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2ams-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Middle",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2aoi-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2aoi-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2aoi-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aoi-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aoi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2aom-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aon", {
								 "Part of Speech: Verb",
								 "Tense: Second Aorist",
								 "Voice: Passive deponent",
								 "Mood: Infinitive"
							 }},
		{"v-2aos-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive deponent",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2api-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2api-1s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2api-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2api-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2api-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2api-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2apm-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2apm-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Imperative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2apm-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Imperative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2apn", {
								 "Part of Speech: Verb",
								 "Tense: Second Aorist",
								 "Voice: Passive",
								 "Mood: Infinitive"
							 }},
		{"v-2app-asm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2app-dsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2app-gpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2app-npf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Feminine"
									 }},
		{"v-2app-npm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2app-nsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2app-nsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2app-nsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2aps-1p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Subjunctive",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2aps-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2aps-2s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2aps-3p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2aps-3s", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: Passive",
										"Mood: Subjunctive",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2axm-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: no voice stated",
										"Mood: Imperative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2axp-gpm", {
										 "Part of Speech: Verb",
										 "Tense: Second Aorist",
										 "Voice: no voice stated",
										 "Mood: Participle",
										 "Case: Genitive",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2axs-2p", {
										"Part of Speech: Verb",
										"Tense: Second Aorist",
										"Voice: no voice stated",
										"Mood: Subjunctive",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2fai-3s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2fdi-3p", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2fdi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Middle deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2fmi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Middle",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2foi-1s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2foi-3p", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2foi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive deponent",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2fpi-1p", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2fpi-2p", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2fpi-2s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2fpi-3p", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2fpi-3s", {
										"Part of Speech: Verb",
										"Tense: Second Future",
										"Voice: Passive",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2lai-3s", {
										"Part of Speech: Verb",
										"Tense: Second Pluperfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2rai-1p", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: First",
										"Number: Plural"
									}},
		{"v-2rai-1p-att", {
												"Part of Speech: Verb",
												"Tense: Second Perfect",
												"Voice: Active",
												"Mood: Indicative",
												"Person: First",
												"Number: Plural",
												"attic form"
											}},
		{"v-2rai-1s", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: First",
										"Number: Singular"
									}},
		{"v-2rai-2p", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Second",
										"Number: Plural"
									}},
		{"v-2rai-2p-att", {
												"Part of Speech: Verb",
												"Tense: Second Perfect",
												"Voice: Active",
												"Mood: Indicative",
												"Person: Second",
												"Number: Plural",
												"attic form"
											}},
		{"v-2rai-2s", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Second",
										"Number: Singular"
									}},
		{"v-2rai-3p", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Plural"
									}},
		{"v-2rai-3p-att", {
												"Part of Speech: Verb",
												"Tense: Second Perfect",
												"Voice: Active",
												"Mood: Indicative",
												"Person: Third",
												"Number: Plural",
												"attic form"
											}},
		{"v-2rai-3p-c", {
											"Part of Speech: Verb",
											"Tense: Second Perfect",
											"Voice: Active",
											"Mood: Indicative",
											"Person: Third",
											"Number: Plural",
											"Contracted form"
										}},
		{"v-2rai-3s", {
										"Part of Speech: Verb",
										"Tense: Second Perfect",
										"Voice: Active",
										"Mood: Indicative",
										"Person: Third",
										"Number: Singular"
									}},
		{"v-2rai-3s-att", {
												"Part of Speech: Verb",
												"Tense: Second Perfect",
												"Voice: Active",
												"Mood: Indicative",
												"Person: Third",
												"Number: Singular",
												"attic form"
											}},
		{"v-2ran", {
								 "Part of Speech: Verb",
								 "Tense: Second Perfect",
								 "Voice: Active",
								 "Mood: Infinitive"
							 }},
		{"v-2rap-apm", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2rap-apm-att", {
												 "Part of Speech: Verb",
												 "Tense: Second Perfect",
												 "Voice: Active",
												 "Mood: Participle",
												 "Case: Accusative",
												 "Number: Plural",
												 "Gender: Masculine",
												 "attic form"
											 }},
		{"v-2rap-apn", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Plural",
										 "Gender: Neuter"
									 }},
		{"v-2rap-asf", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2rap-asm", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2rap-asn", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2rap-dsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Dative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2rap-npm", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Plural",
										 "Gender: Masculine"
									 }},
		{"v-2rap-nsf", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Feminine"
									 }},
		{"v-2rap-nsm", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-2rap-nsn", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Active",
										 "Mood: Participle",
										 "Case: Nominative",
										 "Number: Singular",
										 "Gender: Neuter"
									 }},
		{"v-2rpp-asm", {
										 "Part of Speech: Verb",
										 "Tense: Second Perfect",
										 "Voice: Passive",
										 "Mood: Participle",
										 "Case: Accusative",
										 "Number: Singular",
										 "Gender: Masculine"
									 }},
		{"v-aai-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-aai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-aai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aam-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aam-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aam-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aam-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aan", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Active",
								"Mood: Infinitive"
							}},
		{"v-aao-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aao-3p-a", {
										 "Part of Speech: Verb",
										 "Tense: Aorist",
										 "Voice: Active",
										 "Mood: Optative",
										 "Person: Third",
										 "Number: Plural",
										 "Aeolic"
									 }},
		{"v-aao-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aap-apm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aap-apn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-aap-asf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-aap-asm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aap-asn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-aap-dpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aap-dsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aap-gpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aap-gsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-aap-gsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aap-npf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-aap-npm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aap-nsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-aap-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aap-nsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-aas-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-aas-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-aas-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aas-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aas-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aas-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-adi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-adi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-adi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-adi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-adi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-adi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-adm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-adm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-adm-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-adm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-adn", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Middle deponent",
								"Mood: Infinitive"
							}},
		{"v-ado-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Optative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-adp-apm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-adp-asm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-adp-dpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-adp-gsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-adp-npm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-adp-nsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-adp-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-ads-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ads-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ads-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ads-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ads-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ads-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ami-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ami-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ami-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ami-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ami-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ami-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-amm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-amm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-amm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-amn", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Middle",
								"Mood: Infinitive"
							}},
		{"v-amp-apm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-amp-asn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-amp-dpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-amp-gpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-amp-gsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-amp-npm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-amp-nsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-amp-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-amp-nsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-ams-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ams-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ams-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ams-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ams-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ams-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ani-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ani-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-anp-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-anp-nsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-aoi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-aoi-1p-att", {
											 "Part of Speech: Verb",
											 "Tense: Aorist",
											 "Voice: Passive deponent",
											 "Mood: Indicative",
											 "Person: First",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-aoi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-aoi-1s-att", {
											 "Part of Speech: Verb",
											 "Tense: Aorist",
											 "Voice: Passive deponent",
											 "Mood: Indicative",
											 "Person: First",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-aoi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aoi-2p-att", {
											 "Part of Speech: Verb",
											 "Tense: Aorist",
											 "Voice: Passive deponent",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-aoi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aoi-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Aorist",
											 "Voice: Passive deponent",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-aoi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aoi-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Aorist",
											 "Voice: Passive deponent",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-aom-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aom-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aom-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aon", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Passive deponent",
								"Mood: Infinitive"
							}},
		{"v-aoo-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-aop-apm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aop-asm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aop-dsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aop-gpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aop-gpn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-aop-gsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aop-npf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-aop-npm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-aop-nsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-aop-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-aop-nsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-aos-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-aos-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-aos-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aos-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aos-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aos-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-api", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Passive",
								"Mood: Indicative"
							}},
		{"v-api-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-api-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-api-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-api-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-api-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-api-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-api-3s-m", {
										 "Part of Speech: Verb",
										 "Tense: Aorist",
										 "Voice: Passive",
										 "Mood: Indicative",
										 "Person: Third",
										 "Number: Singular",
										 "Middle significance"
									 }},
		{"v-apm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-apm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-apm-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-apm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-apn", {
								"Part of Speech: Verb",
								"Tense: Aorist",
								"Voice: Passive",
								"Mood: Infinitive"
							}},
		{"v-apn-m", {
									"Part of Speech: Verb",
									"Tense: Aorist",
									"Voice: Passive",
									"Mood: Infinitive",
									"Gender: Masculine"
								}},
		{"v-apo-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-app-apm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-app-apn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-app-asf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-app-asm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-app-asn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-app-dpn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-app-dsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-app-dsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-app-gpf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-app-gpm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-app-gpn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-app-gsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-app-gsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-app-gsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-app-npm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-app-npn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-app-nsf", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-app-nsm", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-app-nsm-m", {
											"Part of Speech: Verb",
											"Tense: Aorist",
											"Voice: Passive",
											"Mood: Participle",
											"Case: Nominative",
											"Number: Singular",
											"Gender: Masculine",
											"Middle significance"
										}},
		{"v-app-nsn", {
										"Part of Speech: Verb",
										"Tense: Aorist",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-aps-1p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-aps-1s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-aps-2p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-aps-2s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-aps-3p", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-aps-3s", {
									 "Part of Speech: Verb",
									 "Tense: Aorist",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fai-1p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-fai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fai-1s-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: First",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-fai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-fai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-fai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fai-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-fai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fai-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-fan", {
								"Part of Speech: Verb",
								"Tense: Future",
								"Voice: Active",
								"Mood: Infinitive"
							}},
		{"v-fap-apn", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-fap-gpm", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-fap-npm", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-fap-nsm", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-fdi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-fdi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fdi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-fdi-2p-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-fdi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-fdi-2s-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-fdi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fdi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fdi-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Future",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-fdn", {
								"Part of Speech: Verb",
								"Tense: Future",
								"Voice: Middle deponent",
								"Mood: Infinitive"
							}},
		{"v-fdp-asn", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-fdp-npm", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-fmi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fmi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-fmi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fmi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fni-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fni-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-foi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-foi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-foi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fpi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-fpi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fpi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-fpi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-fpi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fpi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fpp-gpn", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-fps-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fxi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-fxi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-fxi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-fxi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-fxi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-fxi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Future",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-fxn", {
								"Part of Speech: Verb",
								"Tense: Future",
								"Voice: no voice stated",
								"Mood: Infinitive"
							}},
		{"v-fxp-asn", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-fxp-nsm", {
										"Part of Speech: Verb",
										"Tense: Future",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-iai-1p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-iai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-iai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-iai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-iai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-iai-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Imperfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-iai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-iai-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Imperfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-idi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-iei-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-imi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-imi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-imi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-imi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ini-1p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ini-1s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ini-2p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ini-2p-att", {
											 "Part of Speech: Verb",
											 "Tense: Imperfect",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-ini-2s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ini-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ini-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Imperfect",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-ini-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ini-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Imperfect",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-ipi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ipi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ipi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ipi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ipi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-iqi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: Impersonal active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ixi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ixi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ixi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ixi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ixi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ixi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Imperfect",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-lai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-lai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-lai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-lai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-lai-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Pluperfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-lai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-lai-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Pluperfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-ldi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-lmi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-lpi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Pluperfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pai-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pai-1s-c", {
										 "Part of Speech: Verb",
										 "Tense: Present",
										 "Voice: Active",
										 "Mood: Indicative",
										 "Person: First",
										 "Number: Singular",
										 "Contracted form"
									 }},
		{"v-pai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pai-2s-irr", {
											 "Part of Speech: Verb",
											 "Tense: Present",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Singular",
											 "irregular or inpure form"
										 }},
		{"v-pai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pai-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Present",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-pai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pam-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pam-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pam-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pam-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pan", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Active",
								"Mood: Infinitive"
							}},
		{"v-pao-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Optative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pao-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pao-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pap-apf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pap-apm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pap-apn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pap-asf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pap-asm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pap-asn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pap-dpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pap-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pap-dpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pap-dsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pap-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pap-dsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pap-gpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pap-gpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pap-gpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pap-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pap-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pap-gsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pap-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pap-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pap-npn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pap-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pap-nsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pap-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pas-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pas-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pas-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pas-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pas-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pas-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pdp-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pei-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pei-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pei-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pei-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pei-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pem-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pem-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Either middle or Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pen", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Either middle or Passive",
								"Mood: Infinitive"
							}},
		{"v-pep-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pep-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pep-gpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pep-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pep-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pep-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pep-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pep-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Either middle or Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pmi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pmi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pmi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pmi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pmi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pmm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pmm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pmm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pmn", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Middle",
								"Mood: Infinitive"
							}},
		{"v-pmp-apm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pmp-asf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pmp-asm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pmp-asn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pmp-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pmp-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pmp-gpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pmp-gpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pmp-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pmp-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pmp-gsm-t", {
											"Part of Speech: Verb",
											"Tense: Present",
											"Voice: Middle",
											"Mood: Participle",
											"Case: Genitive",
											"Number: Singular",
											"Gender: Masculine",
											"Transitive"
										}},
		{"v-pmp-gsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pmp-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pmp-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pmp-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pmp-nsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pmp-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pms-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pms-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pms-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pms-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pni-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pni-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pni-1s-c", {
										 "Part of Speech: Verb",
										 "Tense: Present",
										 "Voice: Middle deponent",
										 "Mood: Indicative",
										 "Person: First",
										 "Number: Singular",
										 "Contracted form"
									 }},
		{"v-pni-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pni-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pni-2s-att", {
											 "Part of Speech: Verb",
											 "Tense: Present",
											 "Voice: Middle deponent",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-pni-2s-c", {
										 "Part of Speech: Verb",
										 "Tense: Present",
										 "Voice: Middle deponent",
										 "Mood: Indicative",
										 "Person: Second",
										 "Number: Singular",
										 "Contracted form"
									 }},
		{"v-pni-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pni-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pni-3s-i", {
										 "Part of Speech: Verb",
										 "Tense: Present",
										 "Voice: Middle deponent",
										 "Mood: Indicative",
										 "Person: Third",
										 "Number: Singular"
									 }},
		{"v-pnm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pnm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pnm-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pnm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pnn", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Middle deponent",
								"Mood: Infinitive"
							}},
		{"v-pno-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Optative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pno-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pno-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pnp-apf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pnp-apm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pnp-apn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pnp-asf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pnp-asm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pnp-asn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pnp-dpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pnp-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pnp-dpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pnp-dsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pnp-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pnp-dsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pnp-gpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pnp-gpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pnp-gpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pnp-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pnp-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pnp-gsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pnp-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pnp-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pnp-npn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pnp-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pnp-nsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pnp-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pns-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pns-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pns-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pns-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pns-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pns-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Middle deponent",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pop-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-ppi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ppi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ppi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ppi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ppi-2s-irr", {
											 "Part of Speech: Verb",
											 "Tense: Present",
											 "Voice: Passive",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Singular",
											 "irregular or inpure form"
										 }},
		{"v-ppi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ppi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ppm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ppm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-ppm-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-ppm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-ppn", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Passive",
								"Mood: Infinitive"
							}},
		{"v-ppn-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Infinitive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ppp-apf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-ppp-apm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-ppp-apn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-ppp-asf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-ppp-asm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-ppp-asn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-ppp-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-ppp-dpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-ppp-dsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-ppp-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-ppp-dsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-ppp-gpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-ppp-gpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-ppp-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-ppp-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-ppp-gsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-ppp-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-ppp-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-ppp-npn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-ppp-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-ppp-nsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-ppp-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pps-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pps-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pps-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pps-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pps-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Passive",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pqi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Impersonal active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pqn", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: Impersonal active",
								"Mood: Infinitive"
							}},
		{"v-pqp-apn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Impersonal active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pqp-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: Impersonal active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pqs-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: Impersonal active",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pxi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pxi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pxi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pxi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pxi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pxi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pxm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pxm-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pxm-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Imperative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pxn", {
								"Part of Speech: Verb",
								"Tense: Present",
								"Voice: no voice stated",
								"Mood: Infinitive"
							}},
		{"v-pxo-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Optative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pxo-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Optative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-pxp-apm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pxp-apn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pxp-asf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pxp-asm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pxp-asn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pxp-dpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pxp-dpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pxp-dsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pxp-dsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pxp-gpf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pxp-gpm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pxp-gpn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pxp-gsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pxp-gsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pxp-gsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pxp-npf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-pxp-npm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-pxp-npn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-pxp-nsf", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-pxp-nsm", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-pxp-nsn", {
										"Part of Speech: Verb",
										"Tense: Present",
										"Voice: no voice stated",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-pxs-1p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-pxs-1s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-pxs-2p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-pxs-2s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-pxs-3p", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-pxs-3s", {
									 "Part of Speech: Verb",
									 "Tense: Present",
									 "Voice: no voice stated",
									 "Mood: Subjunctive",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rai-1p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-rai-1p-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: First",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-rai-1s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-rai-1s-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: First",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-rai-2p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-rai-2p-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-rai-2s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-rai-2s-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Second",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-rai-3p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-rai-3p-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Plural",
											 "attic form"
										 }},
		{"v-rai-3s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rai-3s-att", {
											 "Part of Speech: Verb",
											 "Tense: Perfect",
											 "Voice: Active",
											 "Mood: Indicative",
											 "Person: Third",
											 "Number: Singular",
											 "attic form"
										 }},
		{"v-ram-2p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ran", {
								"Part of Speech: Verb",
								"Tense: Perfect",
								"Voice: Active",
								"Mood: Infinitive"
							}},
		{"v-ran-att", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Infinitive",
										"Case: Accusative"
									}},
		{"v-rap-apm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rap-apn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rap-asf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rap-asm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rap-asm-c", {
											"Part of Speech: Verb",
											"Tense: Perfect",
											"Voice: Active",
											"Mood: Participle",
											"Case: Accusative",
											"Number: Singular",
											"Gender: Masculine",
											"Contracted form"
										}},
		{"v-rap-asn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rap-dpm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rap-dsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rap-dsn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rap-gpm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rap-gpn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rap-gsf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rap-gsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rap-gsn-att", {
												"Part of Speech: Verb",
												"Tense: Perfect",
												"Voice: Active",
												"Mood: Participle",
												"Case: Genitive",
												"Number: Singular",
												"Gender: Neuter",
												"attic form"
											}},
		{"v-rap-npf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-rap-npm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rap-npm-att", {
												"Part of Speech: Verb",
												"Tense: Perfect",
												"Voice: Active",
												"Mood: Participle",
												"Case: Nominative",
												"Number: Plural",
												"Gender: Masculine",
												"attic form"
											}},
		{"v-rap-npm-c", {
											"Part of Speech: Verb",
											"Tense: Perfect",
											"Voice: Active",
											"Mood: Participle",
											"Case: Nominative",
											"Number: Plural",
											"Gender: Masculine",
											"Contracted form"
										}},
		{"v-rap-npn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rap-nsf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rap-nsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rap-nsm-att", {
												"Part of Speech: Verb",
												"Tense: Perfect",
												"Voice: Active",
												"Mood: Participle",
												"Case: Nominative",
												"Number: Singular",
												"Gender: Masculine",
												"attic form"
											}},
		{"v-rap-nsn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Active",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-ras-1p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-ras-1s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-ras-2p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-ras-2s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Active",
									 "Mood: Subjunctive",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-rdi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rmi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-rmi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rmp-asm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rmp-npm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rmp-nsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rni-1p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-rni-1s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-rni-3s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Middle deponent",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rnn", {
								"Part of Speech: Verb",
								"Tense: Perfect",
								"Voice: Middle deponent",
								"Mood: Infinitive"
							}},
		{"v-rnp-apm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rnp-asf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rnp-dpf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-rnp-npm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rnp-nsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Middle deponent",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rpi-1p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Plural"
								 }},
		{"v-rpi-1s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: First",
									 "Number: Singular"
								 }},
		{"v-rpi-2p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-rpi-2s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-rpi-3p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Plural"
								 }},
		{"v-rpi-3s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Indicative",
									 "Person: Third",
									 "Number: Singular"
								 }},
		{"v-rpm-2p", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-rpm-2s", {
									 "Part of Speech: Verb",
									 "Tense: Perfect",
									 "Voice: Passive",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"v-rpn", {
								"Part of Speech: Verb",
								"Tense: Perfect",
								"Voice: Passive",
								"Mood: Infinitive"
							}},
		{"v-rpp-apf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-rpp-apm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rpp-apn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rpp-asf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rpp-asm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rpp-asn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Accusative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rpp-asn-att", {
												"Part of Speech: Verb",
												"Tense: Perfect",
												"Voice: Passive",
												"Mood: Participle",
												"Case: Accusative",
												"Number: Singular",
												"Gender: Neuter",
												"attic form"
											}},
		{"v-rpp-dpm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rpp-dpn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rpp-dsf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rpp-dsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rpp-dsn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Dative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rpp-gpm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rpp-gpn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rpp-gsf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rpp-gsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rpp-gsn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Genitive",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rpp-npf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Feminine"
									}},
		{"v-rpp-npm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Masculine"
									}},
		{"v-rpp-npn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Plural",
										"Gender: Neuter"
									}},
		{"v-rpp-nsf", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Feminine"
									}},
		{"v-rpp-nsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-rpp-nsn", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Nominative",
										"Number: Singular",
										"Gender: Neuter"
									}},
		{"v-rpp-nsn-att", {
												"Part of Speech: Verb",
												"Tense: Perfect",
												"Voice: Passive",
												"Mood: Participle",
												"Case: Nominative",
												"Number: Singular",
												"Gender: Neuter",
												"attic form"
											}},
		{"v-rpp-vsm", {
										"Part of Speech: Verb",
										"Tense: Perfect",
										"Voice: Passive",
										"Mood: Participle",
										"Case: Vocative",
										"Number: Singular",
										"Gender: Masculine"
									}},
		{"v-xxm-2p", {
									 "Part of Speech: Verb",
									 "Tense: no tense stated",
									 "Voice: no voice stated",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Plural"
								 }},
		{"v-xxm-2s", {
									 "Part of Speech: Verb",
									 "Tense: no tense stated",
									 "Voice: no voice stated",
									 "Mood: Imperative",
									 "Person: Second",
									 "Number: Singular"
								 }},
		{"x-apf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"x-apm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"x-apn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"x-asf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"x-asm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"x-asn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Accusative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"x-dpm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Dative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"x-dsf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"x-dsm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"x-dsn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Dative",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"x-gpf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"x-gpm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"x-gpn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"x-gsf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"x-gsm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"x-gsn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Genitive",
								"Number: Singular",
								"Gender: Neuter"
							}},
		{"x-npf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Feminine"
							}},
		{"x-npm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Masculine"
							}},
		{"x-npn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Plural",
								"Gender: Neuter"
							}},
		{"x-nsf", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Feminine"
							}},
		{"x-nsm", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Masculine"
							}},
		{"x-nsn", {
								"Part of Speech: Indefinite pronoun",
								"Case: Nominative",
								"Number: Singular",
								"Gender: Neuter"
							}}
} {}
