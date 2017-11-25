using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AForge;
using AForge.Fuzzy;

namespace Conjunto_nebuloso
{
    class Program
    {
        static void Main(string[] args)
        {


            LinguisticVariable luminosidade = new LinguisticVariable("luminosidade", 0, 14);

            TrapezoidalFunction tf_escura = new TrapezoidalFunction(1, 5, TrapezoidalFunction.EdgeType.Right);
            FuzzySet escura = new FuzzySet("escura", tf_escura);

            TrapezoidalFunction tf_pouca = new TrapezoidalFunction(1, 5, 6, 8);
            FuzzySet pouca = new FuzzySet("pouca", tf_pouca);

            TrapezoidalFunction tf_media = new TrapezoidalFunction(6, 8, 10, 11);
            FuzzySet media = new FuzzySet("media", tf_media);

            TrapezoidalFunction tf_extrema = new TrapezoidalFunction(9, 12, TrapezoidalFunction.EdgeType.Left);
            FuzzySet extrema = new FuzzySet("extrema", tf_extrema);

            luminosidade.AddLabel(escura);
            luminosidade.AddLabel(pouca);
            luminosidade.AddLabel(media);
            luminosidade.AddLabel(extrema);

            LinguisticVariable profundidade = new LinguisticVariable("profundidade", (float)0, (float)1.4);

            TrapezoidalFunction tf_rasa = new TrapezoidalFunction((float)0.1, (float)0.3, TrapezoidalFunction.EdgeType.Right);
            FuzzySet rasa = new FuzzySet("rasa", tf_rasa);

            TrapezoidalFunction tf_medprof = new TrapezoidalFunction((float)0.1, (float)0.3, (float)0.6, (float)1);
            FuzzySet mediaprof = new FuzzySet("media", tf_medprof);

            TrapezoidalFunction tf_profundo = new TrapezoidalFunction((float)0.6, (float)1, (float)1.2);
            FuzzySet profundo = new FuzzySet("profundo", tf_profundo);

            TrapezoidalFunction tf_muitoprof = new TrapezoidalFunction((float)1, (float)1.2, TrapezoidalFunction.EdgeType.Left);
            FuzzySet muitoprof = new FuzzySet("muito profundo", tf_muitoprof);

            profundidade.AddLabel(rasa);
            profundidade.AddLabel(mediaprof);
            profundidade.AddLabel(profundo);
            profundidade.AddLabel(muitoprof);

            float x = 0;
            float y = 0;
            float profmedia_result = 0;
            float luminopouca_result = 0;
            float profrasa_result = 0;
            float luminoextrema_result = 0;
            float profmuito_result = 0;
            float luminomed_result = 0;
            float luminoesc_result = 0;


            Console.WriteLine("Qual a luminosidade?");
            string n1 = Console.ReadLine();
            x = (float)Convert.ToDouble(n1);

            Console.WriteLine("Qual a profundidade?");
            string n2 = Console.ReadLine();
            y = (float)Convert.ToDouble(n2);

            profmedia_result = profundidade.GetLabelMembership("media", y);

            luminopouca_result = luminosidade.GetLabelMembership("pouca", x);

            profrasa_result = profundidade.GetLabelMembership("rasa", y);

            luminoextrema_result = luminosidade.GetLabelMembership("extrema", x);

            profmuito_result = profundidade.GetLabelMembership("muito profundo", y);

            luminomed_result = luminosidade.GetLabelMembership("media", x);

            luminoesc_result = luminosidade.GetLabelMembership("escura", x);



            Console.WriteLine("Profundidade média e luminosidade pouca = " + Math.Min(profmedia_result, luminopouca_result));

            Console.WriteLine("Profundidade rasa ou Luminosidade extrema =" + Math.Max(profrasa_result, luminoextrema_result));

            Console.WriteLine("Profundidade muito profundo ou profundidade média e luminosidade escura = " + Math.Min(Math.Max(profmuito_result, profmedia_result), luminoesc_result));

            Console.WriteLine("Luminosidade extrema e luminosidade média = " + Math.Min(luminoextrema_result, luminomed_result));







            Console.ReadKey();






        }

    }
}
