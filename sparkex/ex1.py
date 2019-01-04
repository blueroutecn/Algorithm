from pyspark import SparkContext

from pyspark.sql import SparkSession

spark = SparkSession.builder \
     .master("local") \
     .appName("fist app") \
     .config("spark.some.config.option", "some-value") \
     .getOrCreate()

df = spark.read.option("inferSchema", "true")\
        .option("header", "true")\
        .csv("./sparkex/sparkdown/data/flight-data/csv/2015-summary.csv")



df.createOrReplaceTempView("flight_data_2015")

df.take(3)


df.sort("count").take(3)

sqlway = spark.sql("""SELECT DEST_COUNTRY_NAME,count(1) FROM flight_data_2015 GROUP BY DEST_COUNTRY_NAME ORDER BY COUNT(1) DESC""")
sqlway.explain()
sqlway.take(10)

spark.sql("""SELECT DEST_COUNTRY_NAME,count(1) FROM flight_data_2015 GROUP BY DEST_COUNTRY_NAME ORDER BY count(1)""").take(1)

spark.sql("SELECT max(count) from flight_data_2015").take(1)

from pyspark.sql.functions import max
df.select(max("count")).take(1)

df.dtypes
df.select(max("count")).take(1)
df2 = spark.read.option("inferSchema", "true")\
        .option("header", "true")\
        .csv("./sparkex/sparkdown/data/bike-data/201508_trip_data.csv")

from pyspark.sql.functions import desc
df.groupBy("DEST_COUNTRY_NAME")\
  .sum("count")\
  .withColumnRenamed("sum(count)","destination_total")\
  .sort(desc("destination_total"))\
  .limit(5)\
  .show()


df.groupBy("DEST_COUNTRY_NAME").count().sort(desc("count")).show()

/

df2.createOrReplaceTempView("df2data")
df2.dtypes
spark.sql("""SELECT 'Start Date' FROM df2data""").take(20)

for c in df2.columns:
    tmp = c.split(" ")
    if len(tmp) != 1:
        newname = tmp[0] + '_' + tmp[1]
        df2 = df2.withColumnRenamed(c,newname)


df2.dtypes

df2.createOrReplaceTempView("df2data")
spark.sql("""SELECT count(*) from df2data""").take(3)


tup = [('Alice1','A',1),('Alice2','A',1),('Alice3','B',1),('Alice4','B',2),('Alice5','B',2),('Alice6','C',3),('Alice7','C',3),('Alice8','C',3),('Alice9','C',3)]

df3 = spark.createDataFrame(tup,['name','grade','score'])

df3.show()

df3.createOrReplaceTempView("df3data")

spark.sql("""SELECT grade, COUNT(*) FROM df3data GROUP BY grade ORDER BY COUNT(*)""").take(3)

dfnext = spark.sql("""SELECT name FROM df3data WHERE score BETWEEN 0 AND 1 AND grade='B'""")
dfnext.createOrReplaceTempView("dfnextdata")
dfnext.show()

spark.sql("""SELECT grade,COUNT(*) FROM df3data GROUP BY grade ORDER BY count(*) DESC""").show() # 점수 합해서 ordering 하고 싶은데 ?
