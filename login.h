String html = R"(


<!--一个网页遥控器，对用户更加友好-->
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="A remote control on web">
    <meta name="author" content="Dongxu Guo"> 
    <title>BNU EE GREAT!!!</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://seiyria.com/bootstrap-slider/css/bootstrap-slider.css" rel="stylesheet">
    <link rel="stylesheet" href="http://www.bootcss.com/p/bootstrap-switch/static/stylesheets/bootstrapSwitch.css">
    <style>#ex1Slider .slider-selection {background: #BABABA;}</style>
    <script type="text/javascript" src="https://seiyria.com/bootstrap-slider/dependencies/js/modernizr.js"></script>
</head>
<body>
    <h1>LED Control</h1>
    
    <h3>Mode:</h3>
    <div class="well" style="display:flex;flex-direction:column;">
        <div class="switch" data-on-label="Scroll" data-off-label="Static" style="align-self:center;" id="mySwitch">
            <input type="checkbox" checked/>
        </div>
    </div>
    
    <h3>Intensity:</h3>
    <div class="well" style="display:flex;flex-direction:column;">
        <div class="AdjustF" style="align-self:center;">
            <input id="ex1" data-slider-id="ex1Slider" type="text" data-slider-min="0" data-slider-max="15" data-slider-step="1" data-slider-value="2" style="display:none" data-value="2" value="2">
        </div>
    </div>
    
    <div class="col-lg-6" style="float:none;margin:5px;">
        <div class="input-group">
            <input type="text" class="form-control" aria-label="Text input with multiple buttons" id = "value">
              <div class="input-group-btn">
                <button type="button" class="btn btn-default" aria-label="Help" id="help"><span class="glyphicon glyphicon-question-sign"></span></button>
                <button type="button" class="btn btn-default" id = "Submit">Submit</button>
              </div>
        </div><!-- /.input-group -->
    </div>

    <!--
    <h3>Amplitude:</h3>
    <div class="well" style="display:flex;flex-direction:column">
        <div class="AdjustA" style="align-self:center;">
            <input id="ex2" data-slider-id="exSlider" type="text" data-slider-min="10" data-slider-max="10000" data-slider-step="10" data-slider-value="14" style="display:none" data-value="19" value="19">
        </div>
    </div>

    <h3>Duty:</h3>
    <div class="well" style="display:flex;flex-direction:column;">
        <div class="AdjustD" style="align-self:center;">
            <input id="ex3" data-slider-id="ex1Slider" type="text" data-slider-min="0" data-slider-max="100" data-slider-step="10" data-slider-value="50" style="display:none" data-value="19" value="19">
        </div>
    </div>
    
    <h3>AM:</h3>
    <div class="well" style="display:flex;flex-direction:column;">
        <div class="switch" data-on-label="OFF" data-off-label="ON" style="align-self:center;" id="AMSwitch">
            <input type="checkbox" checked/>
        </div>
    </div>
    -->
    <script type="text/javascript" src="https://seiyria.com/bootstrap-slider/dependencies/js/jquery.min.js"></script>
    <script type="text/javascript" src="https://seiyria.com/bootstrap-slider/js/bootstrap-slider.js"></script>
    <script type="text/javascript" src="https://seiyria.com/bootstrap-slider/dependencies/js/highlight.min.js"></script>
    <script src="http://cdn.bootcss.com/twitter-bootstrap/2.3.1/js/bootstrap.min.js"></script>
    <script src="http://www.bootcss.com/p/bootstrap-switch/static/js/bootstrapSwitch.js"></script>
    <script type="text/javascript">
      $(document).ready(function() {
        $('#ex1').slider({
              formatter: function(value) {
                return 'Current value: ' + value;
              }
          });
            /*
            $('#ex2').slider({
              formatter: function(value) {
                return 'Current value: ' + value;
              }
            });
            
            $('#ex3').slider({
              formatter: function(value) {
                return 'Current value: ' + value;
              }
          });
            */
            $('#ex1').on("slideStop", function() {
                //console.log(document.getElementById("ex1").value);
                $.post(document.domain , {Frequency:document.getElementById("ex1").value,EOF:"True"});
            });
            /*
            $('#ex2').on("slideStop", function() {
                $.post(document.domain , {Amplitude:document.getElementById("ex2").value,EOF:"True"});
            });

            $('#ex3').on("slideStop", function() {
                $.post(document.domain , {Duty:document.getElementById("ex3").value,EOF:"True"});
            });
            */
            /*
            $('#AMSwitch').on('switch-change', function (e, data) {
                var $el = $(data.el)
                , value = data.value;
                $.post(document.domain , {AMState:value,EOF:"True"});
            });
            */
            $('#mySwitch').on('switch-change', function (e, data) {
                var $el = $(data.el)
                , value = data.value;
                $.post(document.domain , {Waveform:value,EOF:"True"});
            });

            $("button").click(function(e){
                var item = e.target;
                var value = e.target.id; 
                if(value == "Submit"){
                    $.post(document.domain , {Text:document.getElementById('value').value, EOF:'\r'});
                }
            });
    });
    </script>

</body>
</html>
)";
