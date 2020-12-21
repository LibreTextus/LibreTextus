#include "grammar.hpp"
#define _noop(String) String

Libre::Grammar::Grammar() : grammar_map{
		{"a-apf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
						}},
		{"a-apf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-apm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"a-apm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-apn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"a-apn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"a-asf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"a-asf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-asf-s", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Superlative")
								}},
		{"a-asm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"a-asm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-asn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"a-asn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"a-dpf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"a-dpm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"a-dpm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-dpn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"a-dsf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"a-dsf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-dsf-s", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Superlative")
								}},
		{"a-dsm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"a-dsm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-dsm-s", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Degree: Superlative")
								}},
		{"a-dsn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"a-dsn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"adv", {
							_noop("Adverb or adverb and particle combined")
						}},
		{"adv-c", {
								_noop("Part of Speech: Adverb"),
								_noop("Contracted form")
							}},
		{"adv-i", {
								_noop("Part of Speech: Adverb"),
								_noop("Interrogative")
							}},
		{"adv-s", {
								_noop("Part of Speech: Adverb"),
								_noop("Degree: Superlative")
							}},
		{"a-gms", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Gender: Masculine"),
								_noop("Degree: Superlative")
							}},
		{"a-gpf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"a-gpm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"a-gpm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Genitive"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-gpn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"a-gpn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Genitive"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"a-gsf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"a-gsf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Genitive"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-gsm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"a-gsm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Genitive"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-gsn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"a-gsn-s", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Genitive"),
									_noop("Number: Singular"),
									_noop("Gender: Neuter"),
									_noop("Degree: Superlative")
								}},
		{"a-npf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"a-npf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-npm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"a-npm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-npn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"a-npn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"a-npn-s", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Degree: Superlative")
								}},
		{"a-nsf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"a-nsf-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Degree: Comparative")
								}},
		{"a-nsm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"a-nsm-att", {
										_noop("Part of Speech: Adjective"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine"),
										_noop("attic Greek form")
									}},
		{"a-nsm-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Degree: Comparative")
								}},
		{"a-nsn", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"a-nsn-c", {
									_noop("Part of Speech: Adjective"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Gender: Neuter"),
									_noop("Degree: Comparative")
								}},
		{"a-nui", {
								_noop("Indeclinable Numeral")
							}},
		{"a-nui-abb", {
										_noop("Part of Speech: Adjective"),
										_noop("Case: Nominative"),
										_noop("abbreviated form")
									}},
		{"aram", {
							 _noop("aramaic transliterated word")
						 }},
		{"a-vpm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Vocative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"a-vsf", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Vocative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"a-vsm", {
								_noop("Part of Speech: Adjective"),
								_noop("Case: Vocative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"c-apm", {
								_noop("Part of Speech: Reciprocal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"c-dpm", {
								_noop("Part of Speech: Reciprocal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"c-dpn", {
								_noop("Part of Speech: Reciprocal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"c-gpm", {
								_noop("Part of Speech: Reciprocal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"c-gpn", {
								_noop("Part of Speech: Reciprocal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"cond", {
							 _noop("conditional particle or conjunction"),
						 }},
		{"cond-c", {
								 _noop("Part of Speech: Contracted form")
							 }},
		{"cond-p", {
								 _noop("Part of Speech: Contracted form")
							 }},
		{"conj", {
							 _noop("conjunction or conjunctive particle")
						 }},
		{"d-apf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"d-apm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"d-apm-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Contracted form")
								}},
		{"d-apn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"d-asf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"d-asm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"d-asm-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Contracted form")
								}},
		{"d-asn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"d-dpf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"d-dpm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"d-dpm-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Dative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Contracted form")
								}},
		{"d-dpn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"d-dsf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"d-dsm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"d-dsn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"d-gpf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"d-gpm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"d-gpn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"d-gsf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"d-gsm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"d-gsn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"d-npf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"d-npm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"d-npm-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Masculine"),
									_noop("Contracted form")
								}},
		{"d-npn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"d-npn-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Nominative"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Contracted form")
								}},
		{"d-nsf", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"d-nsm", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"d-nsm-c", {
									_noop("Part of Speech: Demonstrative pronoun"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Contracted form")
								}},
		{"d-nsn", {
								_noop("Part of Speech: Demonstrative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"f-1asm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-1dsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-1gsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-2asm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-2asm-c", {
									 _noop("Part of Speech: Reflexive pronoun"),
									 _noop("Person: Second"),
									 _noop("Case: Accusative"),
									 _noop("Number: Singular"),
									 _noop("Gender: Masculine"),
									 _noop("Contracted form")
								 }},
		{"f-2dsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-2gsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3apf", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"f-3apm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3apn", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"f-3asf", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"f-3asm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3asn", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"f-3dpf", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"f-3dpm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3dsf", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"f-3dsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3gpm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Genitive"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"f-3gsf", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"f-3gsm", {
								 _noop("Part of Speech: Reflexive pronoun"),
								 _noop("Person: Third"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"f-gpf", {
								_noop("Part of Speech: Reflexive pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"heb", {
							_noop("hebrew transliterated word"),
						}},
		{"i-apf", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"i-apm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"i-asf", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"i-asm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"i-asn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"i-dpm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"i-dsf", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"i-dsm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"i-dsn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"i-gpm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"i-gpn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"i-gsf", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"i-gsm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"i-gsn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"inj", {
							_noop("Interjection")
						}},
		{"i-npm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"i-npn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"i-nsf", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"i-nsm", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"i-nsn", {
								_noop("Part of Speech: Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"k-apf", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"k-apm", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"k-apn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"k-asm", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"k-asn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"k-dsn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"k-gpm", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"k-gsn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"k-npf", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"k-npm", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"k-npn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"k-nsm", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"k-nsn", {
								_noop("Part of Speech: Correlative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"n-apf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"n-apf-c", {
									_noop("Part of Speech: Noun"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Feminine"),
									_noop("Contracted form")
								}},
		{"n-apm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"n-apn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"n-apn-c", {
									_noop("Part of Speech: Noun"),
									_noop("Case: Accusative"),
									_noop("Number: Plural"),
									_noop("Gender: Neuter"),
									_noop("Contracted form")
								}},
		{"n-asf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"n-asf-c", {
									_noop("Part of Speech: Noun"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Feminine"),
									_noop("Contracted form")
								}},
		{"n-asm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"n-asn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"n-dpf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"n-dpm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"n-dpn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"n-dsf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"n-dsm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"n-dsn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"n-gmp", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Gender: Masculine"),
								_noop("Particle attached")
							}},
		{"n-gpf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"n-gpm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"n-gpn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"n-gsf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"n-gsm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"n-gsn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"n-li", {
							 _noop("Indeclinable Letter"),
						 }},
		{"n-nam", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative")
							}},
		{"n-npf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"n-npm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"n-npn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"n-nsf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"n-nsm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"n-nsn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"n-nsn-c", {
									_noop("Part of Speech: Noun"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Gender: Neuter"),
									_noop("Contracted form")
								}},
		{"n-oi", {
							 _noop("Indeclinable Noun of Other type")
						 }},
		{"n-pri", {
								_noop("Indeclinable Proper Noun")
							}},
		{"n-vpf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"n-vpm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"n-vpn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"n-vsf", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"n-vsm", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"n-vsn", {
								_noop("Part of Speech: Noun"),
								_noop("Case: Vocative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"p-1ap", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Accusative"),
								_noop("Number: Plural")
							}},
		{"p-1as", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Accusative"),
								_noop("Number: Singular")
							}},
		{"p-1as-c", {
									_noop("Part of Speech: Personal pronoun"),
									_noop("Person: First"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Contracted form")
								}},
		{"p-1dp", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Dative"),
								_noop("Number: Plural")
							}},
		{"p-1ds", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Dative"),
								_noop("Number: Singular")
							}},
		{"p-1ds-c", {
									_noop("Part of Speech: Personal pronoun"),
									_noop("Person: First"),
									_noop("Case: Dative"),
									_noop("Number: Singular"),
									_noop("Contracted form")
								}},
		{"p-1gp", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Genitive"),
								_noop("Number: Plural")
							}},
		{"p-1gs", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Genitive"),
								_noop("Number: Singular")
							}},
		{"p-1np", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Nominative"),
								_noop("Number: Plural")
							}},
		{"p-1ns", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: First"),
								_noop("Case: Nominative"),
								_noop("Number: Singular")
							}},
		{"p-1ns-c", {
									_noop("Part of Speech: Personal pronoun"),
									_noop("Person: First"),
									_noop("Case: Nominative"),
									_noop("Number: Singular"),
									_noop("Contracted form")
								}},
		{"p-2ap", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Accusative"),
								_noop("Number: Plural")
							}},
		{"p-2as", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Accusative"),
								_noop("Number: Singular")
							}},
		{"p-2dp", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Dative"),
								_noop("Number: Plural")
							}},
		{"p-2ds", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Dative"),
								_noop("Number: Singular")
							}},
		{"p-2gp", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Genitive"),
								_noop("Number: Plural")
							}},
		{"p-2gs", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Genitive"),
								_noop("Number: Singular")
							}},
		{"p-2np", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Nominative"),
								_noop("Number: Plural")
							}},
		{"p-2ns", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Person: Second"),
								_noop("Case: Nominative"),
								_noop("Number: Singular")
							}},
		{"p-apf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"p-apm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"p-apn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"p-asf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"p-asm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"p-asn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"p-dpf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"p-dpm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"p-dpn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"p-dsf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"p-dsm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"p-dsn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"p-gpf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"p-gpm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"p-gpn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"p-gsf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"p-gsm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"p-gsn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"p-npm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"p-npn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"p-nsf", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"p-nsm", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"p-nsn", {
								_noop("Part of Speech: Personal pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"prep", {
							 _noop("preposition")
						 }},
		{"prt", {
							_noop("Particle, disjunctive particle")
						}},
		{"prt-i", {
								_noop("Part of Speech: Particle"),
								_noop("Interrogative")
							}},
		{"prt-n", {
								_noop("Part of Speech: Particle"),
								_noop("Negative")
							}},
		{"q-apf", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"q-apm", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"q-apn", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"q-asf", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"q-asn", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"q-dsn", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"q-gpn", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"q-npf", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"q-npm", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"q-nsm", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"q-nsn", {
								_noop("Part of Speech: Correlative or Interrogative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"r-apf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"r-apm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"r-apn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"r-asf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"r-asm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"r-asm-p", {
									_noop("Part of Speech: Relative pronoun"),
									_noop("Case: Accusative"),
									_noop("Number: Singular"),
									_noop("Gender: Masculine"),
									_noop("Particle attached")
								}},
		{"r-asn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"r-dpf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"r-dpm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"r-dpn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"r-dsf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"r-dsm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"r-dsn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"r-gpf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"r-gpm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"r-gpn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"r-gsf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"r-gsm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"r-gsn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"r-gsn-att", {
										_noop("Part of Speech: Relative pronoun"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter"),
										_noop("attic Greek form")
									}},
		{"r-npf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"r-npm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"r-npn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"r-nsf", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"r-nsm", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"r-nsn", {
								_noop("Part of Speech: Relative pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"s-1apf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1apm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1apn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1asf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1asm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1asn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1dpf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1dpm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1dpn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1dsf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1dsm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1dsn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1gpf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Genitive"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1gpn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Genitive"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1gsf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1npf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1npm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1npn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-1nsf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-1nsm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"s-1nsn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: First"),
								 _noop("Case: Nominative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"s-2apf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2apm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-2apn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-2asf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2asn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Accusative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"s-2dpf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2dpm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Dative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-2dsf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2dsm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Dative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"s-2gpf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Genitive"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2gsf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Genitive"),
								 _noop("Number: Singular"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2npf", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Feminine")
							 }},
		{"s-2npm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Masculine")
							 }},
		{"s-2npn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Nominative"),
								 _noop("Number: Plural"),
								 _noop("Gender: Neuter")
							 }},
		{"s-2nsm", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Nominative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Masculine")
							 }},
		{"s-2nsn", {
								 _noop("Part of Speech: Posessive pronoun"),
								 _noop("Person: Second"),
								 _noop("Case: Nominative"),
								 _noop("Number: Singular"),
								 _noop("Gender: Neuter")
							 }},
		{"t-apf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"t-apm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"t-apn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"t-asf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"t-asm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"t-asn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"t-dpf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"t-dpm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"t-dpn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"t-dsf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"t-dsm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"t-dsn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"t-gpf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"t-gpm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"t-gpn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"t-gsf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"t-gsm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"t-gsn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"t-npf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"t-npm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"t-npn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"t-nsf", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"t-nsm", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"t-nsn", {
								_noop("Part of Speech: Definite article"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"v-2aai-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2aai-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2aai-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aai-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2aai-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aai-3p-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Aorist"),
												_noop("Voice: Active"),
												_noop("Mood: Indicative"),
												_noop("Person: Third"),
												_noop("Number: Plural"),
												_noop("attic form")
											}},
		{"v-2aai-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2aam-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aam-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2aam-2s-ap", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Second Aorist"),
											 _noop("Voice: Active"),
											 _noop("Mood: Imperative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("Apocopated form")
										 }},
		{"v-2aam-2s-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Aorist"),
												_noop("Voice: Active"),
												_noop("Mood: Imperative"),
												_noop("Person: Second"),
												_noop("Number: Singular"),
												_noop("attic form")
											}},
		{"v-2aam-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Imperative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aam-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Imperative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2aan", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Aorist"),
								 _noop("Voice: Active"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2aao-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Optative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aao-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Optative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2aap-apf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-apm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-asf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-asm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-asn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2aap-dpf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-dpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-dsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-dsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-gpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-gsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-gsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-gsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2aap-npf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-npm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-npn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2aap-nsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2aap-nsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2aap-nsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2aas-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2aas-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2aas-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aas-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2aas-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aas-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2adi-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2adi-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2adi-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2adi-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2adi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2adm-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2adm-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2adm-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Imperative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2adn", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Aorist"),
								 _noop("Voice: Middle deponent"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2ado-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Optative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2ado-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Optative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2adp-apm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-apn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2adp-asf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2adp-asm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-asn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2adp-dpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-dpn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2adp-gpf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2adp-gpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-gpn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2adp-gsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2adp-gsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-gsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2adp-npf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2adp-npm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2adp-nsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2ads-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2ads-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2ads-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2ads-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2ads-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2ami-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2ami-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2ami-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2ami-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2ami-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2ami-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2amm-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2amm-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2amn", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Aorist"),
								 _noop("Voice: Middle"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2amp-gsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2amp-npm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2amp-nsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Middle"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2ams-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2ams-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2ams-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2ams-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2ams-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2aoi-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2aoi-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2aoi-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aoi-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aoi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2aom-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aon", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Aorist"),
								 _noop("Voice: Passive deponent"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2aos-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2api-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2api-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2api-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2api-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2api-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2api-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2apm-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2apm-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2apm-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Imperative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2apn", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Aorist"),
								 _noop("Voice: Passive"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2app-asm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2app-dsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2app-gpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2app-npf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2app-npm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2app-nsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2app-nsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2app-nsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2aps-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Subjunctive"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2aps-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2aps-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2aps-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2aps-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2axm-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Imperative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2axp-gpm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Aorist"),
										 _noop("Voice: no voice stated"),
										 _noop("Mood: Participle"),
										 _noop("Case: Genitive"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2axs-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Aorist"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Subjunctive"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2fai-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2fdi-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2fdi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2fmi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Middle"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2foi-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2foi-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2foi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2fpi-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2fpi-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2fpi-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2fpi-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2fpi-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2lai-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Pluperfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2rai-1p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Plural")
									}},
		{"v-2rai-1p-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Indicative"),
												_noop("Person: First"),
												_noop("Number: Plural"),
												_noop("attic form")
											}},
		{"v-2rai-1s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: First"),
										_noop("Number: Singular")
									}},
		{"v-2rai-2p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Plural")
									}},
		{"v-2rai-2p-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Indicative"),
												_noop("Person: Second"),
												_noop("Number: Plural"),
												_noop("attic form")
											}},
		{"v-2rai-2s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Second"),
										_noop("Number: Singular")
									}},
		{"v-2rai-3p", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Plural")
									}},
		{"v-2rai-3p-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Indicative"),
												_noop("Person: Third"),
												_noop("Number: Plural"),
												_noop("attic form")
											}},
		{"v-2rai-3p-c", {
											_noop("Part of Speech: Verb"),
											_noop("Tense: Second Perfect"),
											_noop("Voice: Active"),
											_noop("Mood: Indicative"),
											_noop("Person: Third"),
											_noop("Number: Plural"),
											_noop("Contracted form")
										}},
		{"v-2rai-3s", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Second Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Indicative"),
										_noop("Person: Third"),
										_noop("Number: Singular")
									}},
		{"v-2rai-3s-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Second Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Indicative"),
												_noop("Person: Third"),
												_noop("Number: Singular"),
												_noop("attic form")
											}},
		{"v-2ran", {
								 _noop("Part of Speech: Verb"),
								 _noop("Tense: Second Perfect"),
								 _noop("Voice: Active"),
								 _noop("Mood: Infinitive")
							 }},
		{"v-2rap-apm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2rap-apm-att", {
												 _noop("Part of Speech: Verb"),
												 _noop("Tense: Second Perfect"),
												 _noop("Voice: Active"),
												 _noop("Mood: Participle"),
												 _noop("Case: Accusative"),
												 _noop("Number: Plural"),
												 _noop("Gender: Masculine"),
												 _noop("attic form")
											 }},
		{"v-2rap-apn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2rap-asf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2rap-asm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2rap-asn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2rap-dsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Dative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2rap-npm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Plural"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2rap-nsf", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Feminine")
									 }},
		{"v-2rap-nsm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-2rap-nsn", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Active"),
										 _noop("Mood: Participle"),
										 _noop("Case: Nominative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Neuter")
									 }},
		{"v-2rpp-asm", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Second Perfect"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Participle"),
										 _noop("Case: Accusative"),
										 _noop("Number: Singular"),
										 _noop("Gender: Masculine")
									 }},
		{"v-aai-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-aai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-aai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aam-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aam-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aam-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aam-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aan", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Active"),
								_noop("Mood: Infinitive")
							}},
		{"v-aao-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aao-3p-a", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Aorist"),
										 _noop("Voice: Active"),
										 _noop("Mood: Optative"),
										 _noop("Person: Third"),
										 _noop("Number: Plural"),
										 _noop("Aeolic")
									 }},
		{"v-aao-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aap-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-aap-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-aap-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-aap-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-aap-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-aap-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-aap-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aap-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-aas-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-aas-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-aas-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aas-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aas-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aas-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-adi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-adi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-adi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-adi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-adi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-adi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-adm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-adm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-adm-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-adm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-adn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Middle deponent"),
								_noop("Mood: Infinitive")
							}},
		{"v-ado-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Optative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-adp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-adp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-adp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-adp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-adp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-adp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-adp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-ads-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ads-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ads-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ads-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ads-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ads-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ami-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ami-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ami-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ami-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ami-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ami-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-amm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-amm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-amm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-amn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Middle"),
								_noop("Mood: Infinitive")
							}},
		{"v-amp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-amp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-amp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-amp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-ams-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ams-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ams-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ams-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ams-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ams-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ani-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ani-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-anp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-anp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-aoi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-aoi-1p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Aorist"),
											 _noop("Voice: Passive deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: First"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-aoi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-aoi-1s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Aorist"),
											 _noop("Voice: Passive deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: First"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-aoi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aoi-2p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Aorist"),
											 _noop("Voice: Passive deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-aoi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aoi-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Aorist"),
											 _noop("Voice: Passive deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-aoi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aoi-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Aorist"),
											 _noop("Voice: Passive deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-aom-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aom-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aom-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aon", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Passive deponent"),
								_noop("Mood: Infinitive")
							}},
		{"v-aoo-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-aop-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-aop-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-aop-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-aop-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-aop-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-aos-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-aos-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-aos-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aos-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aos-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aos-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-api", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Passive"),
								_noop("Mood: Indicative")
							}},
		{"v-api-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-api-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-api-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-api-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-api-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-api-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-api-3s-m", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Aorist"),
										 _noop("Voice: Passive"),
										 _noop("Mood: Indicative"),
										 _noop("Person: Third"),
										 _noop("Number: Singular"),
										 _noop("Middle significance")
									 }},
		{"v-apm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-apm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-apm-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-apm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-apn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Aorist"),
								_noop("Voice: Passive"),
								_noop("Mood: Infinitive")
							}},
		{"v-apn-m", {
									_noop("Part of Speech: Verb"),
									_noop("Tense: Aorist"),
									_noop("Voice: Passive"),
									_noop("Mood: Infinitive"),
									_noop("Gender: Masculine")
								}},
		{"v-apo-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-app-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-app-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-app-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-app-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-app-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-app-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-app-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-app-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-app-gpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-app-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-app-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-app-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-app-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-app-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-app-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-app-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-app-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-app-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-app-nsm-m", {
											_noop("Part of Speech: Verb"),
											_noop("Tense: Aorist"),
											_noop("Voice: Passive"),
											_noop("Mood: Participle"),
											_noop("Case: Nominative"),
											_noop("Number: Singular"),
											_noop("Gender: Masculine"),
											_noop("Middle significance")
										}},
		{"v-app-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Aorist"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-aps-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-aps-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-aps-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-aps-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-aps-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-aps-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Aorist"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fai-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-fai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fai-1s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: First"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-fai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-fai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-fai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fai-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-fai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fai-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-fan", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Future"),
								_noop("Voice: Active"),
								_noop("Mood: Infinitive")
							}},
		{"v-fap-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-fap-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-fap-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-fap-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-fdi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-fdi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fdi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-fdi-2p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-fdi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-fdi-2s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-fdi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fdi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fdi-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Future"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-fdn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Future"),
								_noop("Voice: Middle deponent"),
								_noop("Mood: Infinitive")
							}},
		{"v-fdp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-fdp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-fmi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fmi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-fmi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fmi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fni-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fni-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-foi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-foi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-foi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fpi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-fpi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fpi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-fpi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-fpi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fpi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fpp-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-fps-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fxi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-fxi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-fxi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-fxi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-fxi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-fxi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Future"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-fxn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Future"),
								_noop("Voice: no voice stated"),
								_noop("Mood: Infinitive")
							}},
		{"v-fxp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-fxp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Future"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-iai-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-iai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-iai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-iai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-iai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-iai-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Imperfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-iai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-iai-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Imperfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-idi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-iei-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-imi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-imi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-imi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-imi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ini-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ini-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ini-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ini-2p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Imperfect"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-ini-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ini-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ini-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Imperfect"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-ini-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ini-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Imperfect"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-ipi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ipi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ipi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ipi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ipi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-iqi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: Impersonal active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ixi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ixi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ixi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ixi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ixi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ixi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Imperfect"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-lai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-lai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-lai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-lai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-lai-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Pluperfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-lai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-lai-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Pluperfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-ldi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-lmi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-lpi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Pluperfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pai-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pai-1s-c", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Present"),
										 _noop("Voice: Active"),
										 _noop("Mood: Indicative"),
										 _noop("Person: First"),
										 _noop("Number: Singular"),
										 _noop("Contracted form")
									 }},
		{"v-pai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pai-2s-irr", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Present"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("irregular or inpure form")
										 }},
		{"v-pai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pai-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Present"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-pai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pam-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pam-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pam-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pam-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pan", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Active"),
								_noop("Mood: Infinitive")
							}},
		{"v-pao-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Optative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pao-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pao-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pap-apf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-dpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-dsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-gpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pap-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pap-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pap-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pas-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pas-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pas-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pas-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pas-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pas-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pdp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pei-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pei-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pei-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pei-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pei-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pem-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pem-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Either middle or Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pen", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Either middle or Passive"),
								_noop("Mood: Infinitive")
							}},
		{"v-pep-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pep-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pep-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pep-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pep-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pep-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pep-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pep-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Either middle or Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pmi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pmi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pmi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pmi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pmi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pmm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pmm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pmm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pmn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Middle"),
								_noop("Mood: Infinitive")
							}},
		{"v-pmp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pmp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pmp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-gpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pmp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pmp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-gsm-t", {
											_noop("Part of Speech: Verb"),
											_noop("Tense: Present"),
											_noop("Voice: Middle"),
											_noop("Mood: Participle"),
											_noop("Case: Genitive"),
											_noop("Number: Singular"),
											_noop("Gender: Masculine"),
											_noop("Transitive")
										}},
		{"v-pmp-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pmp-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pmp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pmp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pmp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pms-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pms-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pms-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pms-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pni-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pni-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pni-1s-c", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Present"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Indicative"),
										 _noop("Person: First"),
										 _noop("Number: Singular"),
										 _noop("Contracted form")
									 }},
		{"v-pni-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pni-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pni-2s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Present"),
											 _noop("Voice: Middle deponent"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-pni-2s-c", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Present"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Indicative"),
										 _noop("Person: Second"),
										 _noop("Number: Singular"),
										 _noop("Contracted form")
									 }},
		{"v-pni-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pni-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pni-3s-i", {
										 _noop("Part of Speech: Verb"),
										 _noop("Tense: Present"),
										 _noop("Voice: Middle deponent"),
										 _noop("Mood: Indicative"),
										 _noop("Person: Third"),
										 _noop("Number: Singular")
									 }},
		{"v-pnm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pnm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pnm-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pnm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pnn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Middle deponent"),
								_noop("Mood: Infinitive")
							}},
		{"v-pno-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Optative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pno-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pno-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pnp-apf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-dpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-dsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-gpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pnp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pnp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pnp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pns-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pns-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pns-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pns-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pns-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pns-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pop-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-ppi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ppi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ppi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ppi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ppi-2s-irr", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Present"),
											 _noop("Voice: Passive"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("irregular or inpure form")
										 }},
		{"v-ppi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ppi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ppm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ppm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-ppm-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-ppm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-ppn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Passive"),
								_noop("Mood: Infinitive")
							}},
		{"v-ppn-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Infinitive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ppp-apf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-dsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-ppp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-ppp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-ppp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pps-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pps-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pps-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pps-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pps-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pqi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Impersonal active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pqn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: Impersonal active"),
								_noop("Mood: Infinitive")
							}},
		{"v-pqp-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Impersonal active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pqp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: Impersonal active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pqs-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: Impersonal active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pxi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pxi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pxi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pxi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pxi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pxi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pxm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pxm-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pxm-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pxn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Present"),
								_noop("Voice: no voice stated"),
								_noop("Mood: Infinitive")
							}},
		{"v-pxo-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Optative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pxo-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Optative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-pxp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-gpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-pxp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-pxp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-pxp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Present"),
										_noop("Voice: no voice stated"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-pxs-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-pxs-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-pxs-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-pxs-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-pxs-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-pxs-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Present"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rai-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-rai-1p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: First"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-rai-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-rai-1s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: First"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-rai-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-rai-2p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-rai-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-rai-2s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Second"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-rai-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-rai-3p-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Plural"),
											 _noop("attic form")
										 }},
		{"v-rai-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rai-3s-att", {
											 _noop("Part of Speech: Verb"),
											 _noop("Tense: Perfect"),
											 _noop("Voice: Active"),
											 _noop("Mood: Indicative"),
											 _noop("Person: Third"),
											 _noop("Number: Singular"),
											 _noop("attic form")
										 }},
		{"v-ram-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ran", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Perfect"),
								_noop("Voice: Active"),
								_noop("Mood: Infinitive")
							}},
		{"v-ran-att", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Infinitive"),
										_noop("Case: Accusative")
									}},
		{"v-rap-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rap-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rap-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-asm-c", {
											_noop("Part of Speech: Verb"),
											_noop("Tense: Perfect"),
											_noop("Voice: Active"),
											_noop("Mood: Participle"),
											_noop("Case: Accusative"),
											_noop("Number: Singular"),
											_noop("Gender: Masculine"),
											_noop("Contracted form")
										}},
		{"v-rap-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rap-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-dsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rap-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rap-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rap-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-gsn-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Participle"),
												_noop("Case: Genitive"),
												_noop("Number: Singular"),
												_noop("Gender: Neuter"),
												_noop("attic form")
											}},
		{"v-rap-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-rap-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-npm-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Participle"),
												_noop("Case: Nominative"),
												_noop("Number: Plural"),
												_noop("Gender: Masculine"),
												_noop("attic form")
											}},
		{"v-rap-npm-c", {
											_noop("Part of Speech: Verb"),
											_noop("Tense: Perfect"),
											_noop("Voice: Active"),
											_noop("Mood: Participle"),
											_noop("Case: Nominative"),
											_noop("Number: Plural"),
											_noop("Gender: Masculine"),
											_noop("Contracted form")
										}},
		{"v-rap-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rap-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rap-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rap-nsm-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Perfect"),
												_noop("Voice: Active"),
												_noop("Mood: Participle"),
												_noop("Case: Nominative"),
												_noop("Number: Singular"),
												_noop("Gender: Masculine"),
												_noop("attic form")
											}},
		{"v-rap-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Active"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-ras-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-ras-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-ras-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-ras-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Active"),
									 _noop("Mood: Subjunctive"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-rdi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rmi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-rmi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rmp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rmp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rmp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rni-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-rni-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-rni-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Middle deponent"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rnn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Perfect"),
								_noop("Voice: Middle deponent"),
								_noop("Mood: Infinitive")
							}},
		{"v-rnp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rnp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rnp-dpf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-rnp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rnp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Middle deponent"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rpi-1p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Plural")
								 }},
		{"v-rpi-1s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: First"),
									 _noop("Number: Singular")
								 }},
		{"v-rpi-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-rpi-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-rpi-3p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Plural")
								 }},
		{"v-rpi-3s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Indicative"),
									 _noop("Person: Third"),
									 _noop("Number: Singular")
								 }},
		{"v-rpm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-rpm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: Perfect"),
									 _noop("Voice: Passive"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"v-rpn", {
								_noop("Part of Speech: Verb"),
								_noop("Tense: Perfect"),
								_noop("Voice: Passive"),
								_noop("Mood: Infinitive")
							}},
		{"v-rpp-apf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-apm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-apn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-asf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-asm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-asn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Accusative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-asn-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Perfect"),
												_noop("Voice: Passive"),
												_noop("Mood: Participle"),
												_noop("Case: Accusative"),
												_noop("Number: Singular"),
												_noop("Gender: Neuter"),
												_noop("attic form")
											}},
		{"v-rpp-dpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-dpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-dsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-dsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-dsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Dative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-gpm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-gpn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-gsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-gsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-gsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Genitive"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-npf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-npm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-npn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Plural"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-nsf", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Feminine")
									}},
		{"v-rpp-nsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-rpp-nsn", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Nominative"),
										_noop("Number: Singular"),
										_noop("Gender: Neuter")
									}},
		{"v-rpp-nsn-att", {
												_noop("Part of Speech: Verb"),
												_noop("Tense: Perfect"),
												_noop("Voice: Passive"),
												_noop("Mood: Participle"),
												_noop("Case: Nominative"),
												_noop("Number: Singular"),
												_noop("Gender: Neuter"),
												_noop("attic form")
											}},
		{"v-rpp-vsm", {
										_noop("Part of Speech: Verb"),
										_noop("Tense: Perfect"),
										_noop("Voice: Passive"),
										_noop("Mood: Participle"),
										_noop("Case: Vocative"),
										_noop("Number: Singular"),
										_noop("Gender: Masculine")
									}},
		{"v-xxm-2p", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: no tense stated"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Plural")
								 }},
		{"v-xxm-2s", {
									 _noop("Part of Speech: Verb"),
									 _noop("Tense: no tense stated"),
									 _noop("Voice: no voice stated"),
									 _noop("Mood: Imperative"),
									 _noop("Person: Second"),
									 _noop("Number: Singular")
								 }},
		{"x-apf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"x-apm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"x-apn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"x-asf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"x-asm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"x-asn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Accusative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"x-dpm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"x-dsf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"x-dsm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"x-dsn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Dative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"x-gpf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"x-gpm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"x-gpn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"x-gsf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"x-gsm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"x-gsn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Genitive"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}},
		{"x-npf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Feminine")
							}},
		{"x-npm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Masculine")
							}},
		{"x-npn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Plural"),
								_noop("Gender: Neuter")
							}},
		{"x-nsf", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Feminine")
							}},
		{"x-nsm", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Masculine")
							}},
		{"x-nsn", {
								_noop("Part of Speech: Indefinite pronoun"),
								_noop("Case: Nominative"),
								_noop("Number: Singular"),
								_noop("Gender: Neuter")
							}}
} {}
