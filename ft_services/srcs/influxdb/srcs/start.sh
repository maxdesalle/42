service influxdb start
sleep 5
echo "create database telegraf" | influx
echo "create user admin with password 'password'" | influx
echo "grant ALL on telegraf to admin" | influx
sleep infinity
