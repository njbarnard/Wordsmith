/*
 * A class which can check a string and determine if it is a prefix or suffix
 * Affix list created by Kevin Flo:
 * https://gist.github.com/kevinflo
*/

#ifndef WORDSMITH_AFFIX_H
#define WORDSMITH_AFFIX_H

#include <unordered_set>

class Affix {

private:
    std::unordered_set <std::string> PrefixSet;
    std::unordered_set <std::string> SuffixSet;

public:
    Affix(){
        PrefixSet = std::unordered_set <std::string>({
             "a", "ab", "abs", "ac", "acet", "aceto", "acr", "acro", "actin", "actino", "ad", "aden", "adeno",
             "ae", "aer", "aero", "af", "afro", "after", "ag", "agr", "agri", "agro", "al", "allo", "ambi", "amphi",
             "an", "ana", "and", "andr", "andro", "anemo", "angio", "anglo", "ano", "antho", "anthrop",
             "anthropo", "ante", "ant", "anth", "anti", "ap", "apo", "aqua", "aque", "aqui", "arc", "arch",
             "archi", "archaeo", "archeo", "aristo", "arithmo", "arterio", "arthr", "arthro", "astr",
             "astro", "at", "atto", "audio", "aut", "auto", "azo", "bacter", "bacteri", "bacterio", "bar",
             "baro", "bathy", "be", "benz", "benzo", "bi", "bin", "biblio", "bio", "blast", "blasto",
             "brachy", "brady", "brom", "bromo", "bronch", "bronchi", "broncho", "bry", "bryo", "by", "bye",
             "caco", "carb", "carbo", "carp", "carpo", "cardi", "cardio", "cel", "celo", "cen", "ceno", "cent",
             "centi", "centr", "centri", "cephal", "cephalo", "chalco", "cheiro", "chem", "chemi",
             "chemico", "chemo", "chino", "chiro", "chlor", "chloro", "choan", "choano", "chol", "chole",
             "christo", "chron", "chrono", "chrys", "chryso", "cine", "circum", "cis", "co", "coel",
             "coelo", "coen", "coeno", "col", "com", "copr", "copro", "con", "contra", "cor", "cosmo",
             "counter", "cryo", "crypto", "cyan", "cyano", "cyber", "cycl", "cyclo", "cyn", "cyno", "cyt",
             "cyto", "de", "dec", "deca", "deci", "deka", "demi", "deoxy", "deuter", "deutero", "di", "dia",
             "di", "dichlor", "dichloro", "dinitro", "dino", "dipl", "diplo", "dis", "di", "dodec",
             "dodeca", "down", "dys", "eco", "ecto", "eigen", "electr", "electro", "em", "en", "end",
             "endo", "ennea", "ent", "ento", "epi", "equi", "ethno", "eu", "eur", "euro", "ever", "ex", "exa",
             "exbi", "exo", "extra", "femto", "ferro", "fluor", "fluori", "fluoro", "for", "fore", "forth",
             "franco", "full", "ful", "gain", "gastr", "gastro", "genito", "geo", "gibi", "giga", "gen",
             "geno", "gymno", "gyn", "gyno", "gyro", "haem", "haemat", "haemo", "hagi", "hagio", "half",
             "hect", "hecto", "heli", "helio", "hem", "hemat", "hemi", "hemo", "hendeca", "hept", "hepta",
             "hetero", "hex", "hexa", "hind", "hinder", "hipp", "hippo", "hispano", "hist", "histio",
             "histo", "hol", "holo", "homeo", "homo", "homoeo", "hydro", "hyper", "hypn", "hypno", "hypo",
             "il", "ill", "im", "in", "ind", "indo", "inter", "intra", "ir", "is", "iso", "italo", "ker", "kibi",
             "kilo", "kuli", "like", "lip", "lipo", "lith", "litho", "macr", "macro", "mal", "many", "mani",
             "mebi", "mega", "mes", "meso", "meta", "metro", "micr", "micro", "mid", "midi", "milli", "mini",
             "mis", "miso", "mon", "mono", "multi", "myria", "myxo", "nano", "naso", "necr", "necro", "neo",
             "non", "nona", "oct", "octa", "octo", "off", "olig", "oligo", "omni", "on", "orth", "other",
             "out", "over", "ov", "ovi", "ovo", "palaeo", "pale", "paleo", "par", "pebi", "pent", "penta",
             "peta", "phon", "phono", "photo", "phys", "physi", "physio", "pico", "post", "poly",
             "praeter", "pre", "preter", "prot", "proto", "pseud", "pseudo", "psych", "psycho", "pter",
             "ptero", "pyro", "quadr", "quadri", "quadru", "quarter", "quasi", "quin", "quinqu", "quinque",
             "radi", "radio", "re", "robo", "ribo", "same", "schiz", "schizo", "self", "semi", "sept", "septa",
             "septem", "septi", "sex", "sexa", "sino", "step", "sub", "sui", "super", "supra", "syl", "sym", "syn",
             "tebi", "tele", "ter", "tera", "tetr", "tetra", "therm", "thermo", "thorough", "to", "trans", "tri",
             "twi", "ultra", "um", "umbe", "un", "under", "uni", "up", "ur", "uro", "vice", "wan", "well", "wiki",
             "with", "xeno", "xero", "xylo", "y", "yocto", "yotta", "zepto", "zetta", "zo", "zoo" });

        SuffixSet = std::unordered_set <std::string>({
            "a", "ability", "able", "ably", "ac", "acean", "aceous", "ad", "ade", "aemia", "age", "agog",
            "agogue", "aholic", "al", "algia", "all", "amine", "an", "ana", "ance", "ancy", "androus", "andry",
            "ane", "ant", "ar", "arch", "archy", "ard", "arian", "arium", "art", "ary", "ase", "ate", "athon",
            "ation", "ative", "ator", "atory", "biont", "biosis", "blast", "bot", "cade", "caine", "carp", "carpic",
            "carpous", "cele", "cene", "centric", "cephalic", "cephalous", "cephaly", "chore", "chory", "chrome",
            "cide", "clast", "clinal", "cline", "clinic", "coccus", "coel", "coele", "colous", "cracy", "crat",
            "cratic", "cratical", "cy", "cyte", "dale", "derm", "derma", "dermatous", "dom", "drome", "dromous",
            "ean", "eaux", "ectomy", "ed", "ee", "eer", "ein", "eme", "emia", "en", "ence", "enchyma", "ency", "ene",
            "ent", "eous", "er", "ergic", "ergy", "es", "escence", "escent", "ese", "esque", "ess", "est", "et", "eth",
            "etic", "ette", "ey", "facient", "faction", "fer", "ferous", "fic", "fication", "fid", "florous", "fold",
            "foliate", "foliolate", "form", "fuge", "ful", "fy", "gamous", "gamy", "gate", "gen", "gene", "genesis",
            "genetic", "genic", "genous", "geny", "gnathous", "gon", "gony", "gram", "graph", "grapher", "graphy",
            "gyne", "gynous", "gyny", "hood", "ia", "ial", "ian", "iana", "iasis", "iatric", "iatrics", "iatry",
            "ibility", "ible", "ic", "icide", "ician", "ick", "ics", "id", "ide", "ie", "ify", "ile", "in", "ine",
            "ing", "ion", "ious", "isation", "ise", "ish", "ism", "ist", "istic", "istical", "istically", "ite",
            "itious", "itis", "ity", "ium", "ive", "ix", "ization", "ize", "kin", "kinesis", "kins", "latry", "le",
            "lepry", "less", "let", "like", "ling", "lite", "lith", "lithic", "log", "logue", "logic", "logical",
            "logist", "logy", "ly", "lyse", "lysis", "lyte", "lytic", "lyze", "mancy", "mania", "meister", "ment",
            "mer", "mere", "merous", "meter", "metric", "metrics", "metry", "mire", "mo", "morph", "morphic",
            "morphism", "morphous", "most", "mycete", "mycin", "n't", "nasty", "ness", "nik", "nomy", "nomics",
            "o", "ode", "odon", "odont", "odontia", "oholic", "oic", "oid", "ol", "ole", "oma", "ome", "omics",
            "on", "one", "ont", "onym", "onymy", "opia", "opsis", "opsy", "or", "orama", "ory", "ose", "osis",
            "otic", "otomy", "ous", "para", "parous", "path", "pathy", "ped", "pede", "penia", "petal", "phage",
            "phagia", "phagous", "phagy", "phane", "phasia", "phil", "phile", "philia", "philiac", "philic",
            "philous", "phobe", "phobia", "phobic", "phone", "phony", "phore", "phoresis", "phorous", "phrenia",
            "phyll", "phyllous", "plasia", "plasm", "plast", "plastic", "plasty", "plegia", "plex", "ploid",
            "pod", "pode", "podous", "poieses", "poietic", "pter", "punk", "rrhagia", "rrhea", "ric", "ry", "s",
            "scape", "scope", "scopy", "scribe", "script", "sect", "sepalous", "ship", "some", "speak", "sperm",
            "sphere", "sporous", "st", "stasis", "stat", "ster", "stome", "stomy", "taxis", "taxy", "tend", "th",
            "therm", "thermal", "thermic", "thermy", "thon", "thymia", "tion", "tome", "tomy", "tonia", "trichous",
            "trix", "tron", "trophic", "trophy", "tropic", "tropism", "tropous", "tropy", "tude", "ture", "ty",
            "ular", "ule", "ure", "urgy", "uria", "uronic", "urous", "valent", "virile", "vorous", "ward", "wards",
            "ware", "ways", "wear", "wide", "wise", "worthy", "xor", "y", "yl", "yne", "zilla", "zoic", "zoon",
            "zygous", "zyme" });
    }

    bool isPrefix(const std::string& s){
        if (PrefixSet.find(s) != PrefixSet.end()) return true;
        else return false;
    }

    bool isSuffix(const std::string& s){
        if (SuffixSet.find(s) != SuffixSet.end()) return true;
        else return false;
    }
};


#endif //WORDSMITH_AFFIX_H
